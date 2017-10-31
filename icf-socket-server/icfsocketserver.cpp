// icfsocketserver.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "server.h"
int main()
{
	server* pS = new server(2185);

    return 0;
}

