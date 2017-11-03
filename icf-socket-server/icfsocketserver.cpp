// icfsocketserver.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "server.h"
#include "../lib/LinkList.h"
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
		client_ip clientMsg = server::getSocketMsg(client);
		cout << clientMsg.ip;
		cout << "�յ�����\n" << "ip:" << clientMsg.ip << "\t port:" << clientMsg.port;
	}
	void onError(int client) {
		cout << "����";
	}
};
int main()
{
	//�൱��һ��demo
	server* pS = new server(2185, new events());
	LinkList<int> list;
	while (true)
	{
		int ctrl = 0;
		cin >> ctrl;
		switch (ctrl) {
		case 1: {//¼��
			int i = 0;
			cin >> i;
			list.add(i);
			break;
		}
		case 2: {//ɾ��
			int i = 0;
			cin >> i;
			list.del(i);
			break;
		}
		case 3: {//����
			int pos = 0,data=0;
			cin >> pos >> data;
			list.insert(pos,data);
		}
		}
		for (size_t i = 0; i < list.length; i++)
		{
			cout << (list[i])->data << "\t";
		}
		cout << endl;
	}
	return 0;
}
