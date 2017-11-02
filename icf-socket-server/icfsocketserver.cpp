// icfsocketserver.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "server.h"
using namespace std;
using namespace icf;

class events :public callback {
public:
	void onMessage(int client) {
		cout << "收到消息\n";
	}
	void onClose(int client) {
		cout << "断开连接\n";
	}
	void onAccpet(int client) {
		client_ip clientMsg=server::getClientMsg(client);
		cout << clientMsg.ip;
		cout << "收到连接\n"<<"ip:"<<clientMsg.ip<<"\t port:"<<clientMsg.port;
	}
	void onError(int client) {
		cout << "错误";
	}
};
int main()
{
	//相当是一个demo
	server* pS = new server(2185, new events());
	while (true);
	return 0;
}
