#include "stdafx.h"
#include "server.h"

int server::init(int port) {
	m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//����TCP�׽���
	if (m_hSocket == INVALID_SOCKET) {
		return m_hSocket;
	}
	sockaddr_in sIn;
	sIn.sin_addr.S_un.S_addr = INADDR_ANY;
	sIn.sin_port = port;
	sIn.sin_family = AF_INET;
	if (bind(m_hSocket, (LPSOCKADDR)&sIn, sizeof(sIn)) == SOCKET_ERROR)
	{
		return -1;
	}
	if (listen(m_hSocket, 5) == SOCKET_ERROR)
	{
		return -2;
	}
	//�����ɹ���,�����̼߳���
	CreateThread(NULL, 0, server::workThread, this, 0, NULL);
	return 0;
}

DWORD WINAPI server::workThread(LPVOID lpParam) {
	server* socket = (server*)lpParam;
	fd_set fs;
	while (true) {
		//select(NULL,&fs,);
	}
	return 0;
}

