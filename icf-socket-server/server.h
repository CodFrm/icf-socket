#pragma once
//header file
#include <winsock2.h>
#include <windows.h>
#include <wininet.h>
//lib
#pragma comment(lib, "ws2_32.lib")
namespace icf {
	class callback;
	struct client_ip
	{
		char ip[64];
		int port;
	};
	class server {
	private:
		SOCKET m_hSocket;
		callback* m_Event;
		static DWORD WINAPI workThread(LPVOID lpParam);
		static DWORD WINAPI listenThread(LPVOID);
	public:
		server() {
			WSADATA  Ws;
			if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
			{
				throw "socket initialization error";
			}

		}
		server(int port, callback* callback) :server() {
			init(port, callback);
		}

		int init(int port, callback* callback);

		static client_ip getClientMsg(SOCKET hClient);

	};
	//事件回调
	class callback
	{
	public:
		virtual void onMessage(int) = 0;//收到消息
		virtual void onAccpet(int) = 0;//收到客户端连接
		virtual void onClose(int) = 0;//客户端断开
		virtual void onError(int) = 0;//错误信息
	private:

	};

};