#include "main.h"

#include <winsock.h>
#include <stdio.h>
#include <iostream>

#define PORT 5150
#define MSGSIZE 1024

#pragma comment(lib, "ws2_32.lib")

int g_iTotalConn = 0;
SOCKET g_ClientSocketArr[FD_SETSIZE];
DWORD WINAPI WorkerThread(LPVOID lpParameter);

int main(int argc, char **args)
{
	WSADATA wsaData;
	SOCKET sListen;
	SOCKET sClient;
	SOCKADDR_IN local;
	SOCKADDR_IN client;
	int iaddrSize = sizeof(SOCKADDR_IN);
	DWORD dwThreadId;

	WSAStartup(0x0202, &wsaData);// Initialize Windows socket library
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);// Create listening socket
	local.sin_addr.S_un.S_addr = htonl(INADDR_LOOPBACK);
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
	int ret = bind(sListen, (struct sockaddr *)&local, sizeof(SOCKADDR_IN));// Bind
	listen(sListen, 3);// Listen
	std::cout << "*****Listen Socket FD: " << sListen << std::endl;

	g_ClientSocketArr[g_iTotalConn++] = sListen;

	CreateThread(NULL, 0, WorkerThread, NULL, 0, &dwThreadId);// Create worker thread

	Sleep(5000);

	while (TRUE)
	{
		sClient = accept(sListen, (struct sockaddr *)&client, &iaddrSize);// Accept a connection
		printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
		std::cout << "*****accept Socket FD: " << sClient << std::endl;

		Sleep(200);
		std::cout << "*****insert accepted socket: " << sClient << std::endl;
		g_ClientSocketArr[g_iTotalConn++] = sClient;// Add socket to g_CliSocketArr
	}
	return 0;
}

DWORD WINAPI WorkerThread(LPVOID lpParam)
{
	int i;
	fd_set fdread;
	int ret;
	struct timeval tempTimeValue = { 1, 0 };
	char szMessage[MSGSIZE];

	while (TRUE)
	{
		FD_ZERO(&fdread);
		for (i = 0; i < g_iTotalConn; i++)
		{
			FD_SET(g_ClientSocketArr[i], &fdread);// We only care read event
		}
		//一个listenSocket的FileDescriptor监听到connect，建立三次握手后，会触发read。如果不accept的话，listenSocket的FileDescriptor一直是可读状态。
		//从listenSocket中，accept获得一个建立连接的FileDescriptor后，listenSocket的FileDescriptor就不可读了。新的FileDescriptor没有数据写入的话，也不可读。
		//
		ret = select(0, &fdread, NULL, NULL, &tempTimeValue);
		
		if (ret == 0)
		{
			continue;// Time expired
		}else if (ret == -1)
		{
			continue;//error
		}
		else
		{
			for (i = 0; i < g_iTotalConn; i++)
			{
				if (FD_ISSET(g_ClientSocketArr[i], &fdread))
				{
					std::cout << "select Socket FD: " << g_ClientSocketArr[i] << std::endl;
					
					ret = recv(g_ClientSocketArr[i], szMessage, MSGSIZE, 0);

					std::cout << "recv ret: " << ret << std::endl;
					if (ret == 0)
					{
						int a = 3;
						/*printf("Client socket %d closed.\n", g_ClientSocketArr);
						closesocket(g_ClientSocketArr[i]);
						if (i < --g_iTotalConn)
						{
							g_ClientSocketArr[i] = g_ClientSocketArr[g_iTotalConn];
						}*/
					}
					else if (ret == SOCKET_ERROR)
					{
						int a = 3;
						printf("recv()函数出错，错误码：%d\n", WSAGetLastError());
					}
					else
					{// We received a message from client
						//szMessage[ret] = '\0';
						//send(g_ClientSocketArr[i], szMessage, strlen(szMessage), 0);

						std::cout << "receive message from client" << std::endl;
					}
				}
			}
		}
	}
	return 0;
}