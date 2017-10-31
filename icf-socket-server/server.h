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
	server(int port):server() {
		
	}

	bool init(int port) {
		m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//´´½¨TCPÌ×½Ó×Ö

	}
};