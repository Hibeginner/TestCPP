#include <winsock.h>
#include <stdio.h>

#define PORT 5150
#define MSGSIZE 1024

#pragma comment(lib, "ws2_32.lib")

DWORD WINAPI WorkerThread(LPVOID lpParameter);

int main(int argc, char **args)
{
	WSADATA wsaData;
	SOCKET clientSocket;
	SOCKET sClient;
	SOCKADDR_IN local;
	SOCKADDR_IN client;
	int iaddrSize = sizeof(SOCKADDR_IN);
	DWORD dwThreadId;

	WSAStartup(0x0202, &wsaData);// Initialize Windows socket library
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);// Create listening socket
	local.sin_addr.S_un.S_addr = htonl(INADDR_LOOPBACK);
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);

	int result = connect(clientSocket, (struct sockaddr *)&local, sizeof(SOCKADDR_IN));
	if (result < 0)
	{
		perror("client connect -1");
		return 1;
	}
	printf("call connect\n");
	Sleep(10000);
	
	char szMessage[MSGSIZE];
	szMessage[0] = 'a';
	szMessage[1] = 'b';
	send(clientSocket, szMessage, strlen(szMessage), 0);

	printf("call send\n");
	Sleep(20000);
	//while (1)
	//{
	//	//a)�ӱ�׼��������ַ���
	//	char buf[1024] = { 0 };
	//	ssize_t read_size = read(0, buf, sizeof(buf) - 1);
	//	if (read_size < 0)
	//	{
	//		perror("read");
	//		return 1;
	//	}
	//	if (read_size == 0)
	//	{
	//		printf("read done!\n");
	//		return 0;
	//	}
	//	buf[read_size] = '\0';
	//	//b)�Ѷ�����ַ������͸�������
	//	write(fd, buf, strlen(buf));
	//	//c)���Դӷ�������ȡ��Ӧ����
	//	char buf_resp[1024] = { 0 };
	//	read_size = read(fd, buf_resp, sizeof(buf_resp) - 1);
	//	if (read_size < 0)
	//	{
	//		perror("read");
	//		return 1;
	//	}
	//	if (read_size == 0)
	//	{
	//		printf("server close socket!\n");
	//		return 0;
	//	}
	//	buf_resp[read_size] = '\0';
	//	//d)����Ӧ�����ӡ����׼�����
	//	printf("server resp: %s\n", buf_resp);
	//}
	
	return 0;
}

