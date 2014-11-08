// testTraderApi.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include ".\ThostTraderApi\ThostFtdcTraderApi.h"
#include "TraderSpi.h"

// UserApi����
CThostFtdcTraderApi* pUserApi;

// ���ò���
char  FRONT_ADDR[] = "tcp://ctpmn1-front1.citicsf.com:51205";		// ǰ�õ�ַ
TThostFtdcBrokerIDType	BROKER_ID = "1017";				// ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "00000001";			// Ͷ���ߴ���
TThostFtdcPasswordType  PASSWORD = "123456";			// �û�����
TThostFtdcInstrumentIDType INSTRUMENT_ID = "if1411";	// ��Լ����
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// ��������
TThostFtdcPriceType	LIMIT_PRICE = 2509;				// �۸�

// ������
int iRequestID = 0;

void main(void)
{
	// ��ʼ��UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// ����UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// ע���¼���
	pUserApi->SubscribePublicTopic(TERT_RESTART);					// ע�ṫ����
	pUserApi->SubscribePrivateTopic(TERT_RESTART);					// ע��˽����
	pUserApi->RegisterFront(FRONT_ADDR);							// connect
	pUserApi->Init();

	pUserApi->Join();
//	pUserApi->Release();
}