// icfsocketserver.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "server.h"
using namespace std;
using namespace icf;

class events :public callback {
public:
	void onMessage(int client) {
		cout << "�յ���Ϣ\n";
	}
	void onClose(int client) {
		cout << "�Ͽ�����\n";
	}
	void onAccpet(int client) {
		client_ip clientMsg=server::getClientMsg(client);
		cout << clientMsg.ip;
		cout << "�յ�����\n"<<"ip:"<<clientMsg.ip<<"\t port:"<<clientMsg.port;
	}
	void onError(int client) {
		cout << "����";
	}
};
int main()
{
	//�൱��һ��demo
	server* pS = new server(2185, new events());
	while (true);
	return 0;
}
