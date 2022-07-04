#include "main.h"

#include <winsock.h>
#include <stdio.h>
#include <iostream>

#define PORT 8082
#define MSGSIZE 1024

#pragma comment(lib, "ws2_32.lib")

int g_iTotalConn = 0;
SOCKET g_ClientSocketArr[FD_SETSIZE];
DWORD WINAPI WorkerThread(LPVOID lpParameter);

void GetSocketOpt(SOCKET fd)
{
	int optVal;
	int optLen = sizeof(int);
	int result = getsockopt(fd, SOL_SOCKET, TCP_NODELAY, (char *)&optVal, &optLen);
	if (result != SOCKET_ERROR)
	{
		int a = 1;
	}
}

void SetSocketOpt(SOCKET fd)
{
	int optVal = 1;
	int optLen = sizeof(int);
	int result = setsockopt(fd, SOL_SOCKET, TCP_NODELAY, (char *)&optVal, optLen);
	if (result != SOCKET_ERROR)
	{
		int a = 1;
	}
}

int main(int argc, char **args)
{
	WSADATA wsaData;
	SOCKET sListenFD;
	SOCKET connectedFD;
	SOCKADDR_IN local;
	SOCKADDR_IN client;
	int iaddrSize = sizeof(SOCKADDR_IN);
	DWORD dwThreadId;

	WSAStartup(0x0202, &wsaData);// Initialize Windows socket library
	sListenFD = socket(AF_INET, SOCK_STREAM, 0);// Create listening socket
	local.sin_addr.S_un.S_addr = htonl(INADDR_LOOPBACK);
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
	int ret = bind(sListenFD, (struct sockaddr *)&local, sizeof(SOCKADDR_IN));// Bind
	listen(sListenFD, 3);// Listen
	std::cout << "*****Listen Socket FD: " << sListenFD << std::endl;
	/*GetSocketOpt(sListenFD);
	SetSocketOpt(sListenFD);
	GetSocketOpt(sListenFD);*/

	g_ClientSocketArr[g_iTotalConn++] = sListenFD;

	CreateThread(NULL, 0, WorkerThread, NULL, 0, &dwThreadId);// Create worker thread

	Sleep(5000);

	while (TRUE)
	{
		connectedFD = accept(sListenFD, (struct sockaddr *)&client, &iaddrSize);// Accept a connection
		printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
		std::cout << "*****accept Socket FD: " << connectedFD << std::endl;
		
		//GetSocketOpt(connectedFD);

		Sleep(200);
		std::cout << "*****insert accepted socket: " << connectedFD << std::endl;
		g_ClientSocketArr[g_iTotalConn++] = connectedFD;// Add socket to g_CliSocketArr
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
		memset(&szMessage, 0, MSGSIZE);

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
						std::cout << "Client socket FD: " << g_ClientSocketArr[i] << "close." << std::endl;
						closesocket(g_ClientSocketArr[i]);
						if (i < --g_iTotalConn)
						{
							g_ClientSocketArr[i] = g_ClientSocketArr[g_iTotalConn];
						}
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
						std::cout << szMessage << std::endl;
						//Sleep(1000);
					}
				}
			}
		}
	}
	return 0;
}