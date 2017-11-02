#include "stdafx.h"
#include "server.h"
#include "WS2tcpip.h"
using namespace icf;
int server::init(int port, callback* callback) {
	m_Event = callback;
	m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//创建TCP套接字
	if (m_hSocket == INVALID_SOCKET) {
		return (int)m_hSocket;
	}
	sockaddr_in sIn;
	sIn.sin_addr.s_addr = htonl(INADDR_ANY);
	sIn.sin_port = htons(port);
	sIn.sin_family = AF_INET;
	if (bind(m_hSocket, (LPSOCKADDR)&sIn, sizeof(sIn)) == SOCKET_ERROR)
	{
		return -1;
	}
	if (listen(m_hSocket, 5) == SOCKET_ERROR)
	{
		return -2;
	}
	//服务器监听线程
	CreateThread(NULL, 0, server::listenThread, this, 0, NULL);
	//创建成功后,创建工作线程
	CreateThread(NULL, 0, server::workThread, this, 0, NULL);
	return 0;
}

DWORD WINAPI server::listenThread(LPVOID lpParam) {
	server* socket = (server*)lpParam;
	while (true)
	{
		SOCKET sClient;
		struct sockaddr client;
		int len = sizeof(client);
		sClient = accept(socket->m_hSocket, &client, &len);
		if (sClient>0) {
			socket->m_Event->onAccpet(sClient);
		}
		else
		{
			socket->m_Event->onError(sClient);
		}
	}
	return 0;
}

client_ip server::getClientMsg(SOCKET hClient) {
	client_ip ret = {"",0};
	struct sockaddr_in sa;
	int len = sizeof(sa);
	if (!getpeername(hClient, (struct sockaddr *)&sa, &len))
	{
		inet_ntop(AF_INET, (void*)&sa.sin_addr, ret.ip, 16);
		ret.port = ntohs(sa.sin_port);
		return ret;
	}
	return ret;
}

DWORD WINAPI server::workThread(LPVOID lpParam) {
	server* socket = (server*)lpParam;
	fd_set fs;
	FD_ZERO(&fs);
	//FD_SET(&fs);
	int iResult = 0;
	while (true) {
		iResult = select(NULL, &fs, NULL, NULL, NULL);
		switch (iResult)
		{
		default:
			break;
		}

	}
	return 0;
}

