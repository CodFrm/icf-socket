#pragma once
//header file
#include <winsock2.h>
#include <windows.h>
#include <wininet.h>
//lib
#pragma comment(lib, "ws2_32.lib")

class server {
private:
	SOCKET m_hSocket;
public:
	server() {
		WSADATA  Ws;
		if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
		{
			throw "socket initialization error";
		}

	}
	server(int port) :server() {
		init(port);
	}

	int init(int port);
	static DWORD WINAPI workThread(LPVOID lpParam);

};
