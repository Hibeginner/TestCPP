
#include<assert.h>
#include<string.h>

#include <winsock.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

//链接静态库ws2_32.lib。不然要在工程属性里配置
#pragma comment(lib, "ws2_32.lib")

const int port = 8888;
int main(int argc, char *argv[])
{
	if (argc < 0)
	{
		printf("need two canshu\n");
		return 1;
	}
	SOCKET listenSock;
	SOCKET connectedSocket;

	WSADATA wsaData;
	WSAStartup(0x0202, &wsaData);// Initialize Windows socket library
	listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert(listenSock >= 0);

	SOCKADDR_IN sever_address;
	sever_address.sin_family = AF_INET;
	sever_address.sin_addr.S_un.S_addr = htonl(INADDR_LOOPBACK);
	sever_address.sin_port = htons(8888);

	int ret = bind(listenSock, (struct sockaddr *)&sever_address, sizeof(SOCKADDR_IN));
	assert(ret != -1);

	ret = listen(listenSock, 1);
	assert(ret != -1);

	/*{
		std::ifstream ifs;
		ifs.open("hello.html", std::ifstream::in);
		if (ifs.is_open())
		{
			int a = 1;
		}
		std::ostringstream tempStringStream;
		tempStringStream << ifs.rdbuf();
		std::string str = tempStringStream.str();

		ifs.close();
	}*/
	

	while (1)
	{
		struct sockaddr_in clientAddress;
		int client_addrlength = sizeof(clientAddress);
		connectedSocket = accept(listenSock, (struct sockaddr *)&clientAddress, &client_addrlength);

		std::cout << "connectedSocket: " << connectedSocket << std::endl;
		if (connectedSocket < 0)
		{
			printf("errno\n");
		}
		else
		{
			char request[1024] = {0};
			recv(connectedSocket, request, 1024, 0);
			int requestLength = strlen(request);
			request[requestLength + 1] = '\0';
			printf("%s\n", request);
			printf("successeful!\n");

			char buf[520] = "HTTP/1.1 200 ok\r\nconnection: close\r\n\r\n";//HTTP响应
			int s = send(connectedSocket, buf, strlen(buf), 0);//发送响应

			std::ifstream ifs;
			ifs.open("hello.html", std::ifstream::in);
			if (ifs.is_open())
			{
				int a = 1;
			}
			std::ostringstream tempStringStream;
			tempStringStream << ifs.rdbuf();
			std::string responseStr = tempStringStream.str();
			int length = responseStr.length();
			send(connectedSocket, responseStr.c_str(), length, 0);

			ifs.close();
			closesocket(connectedSocket);//一次完整的http请求，以closesocket结束
		}
	}
	return 0;
}