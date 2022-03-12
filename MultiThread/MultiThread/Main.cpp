#include "Main.h"

DWORD WINAPI Fun1Proc(LPVOID lpParamter);
DWORD WINAPI Fun2Proc(LPVOID lpParamter);

int count = 0;
int maxCount = 500;
int maxTicketNum = 100;
HANDLE mutex;
void main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	if (INVALID_HANDLE_VALUE == hThread1) {//INVALID_HANDLE_VALUE   #define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1) 把负1做了2次强制类型转换
		int a = 1;
	}
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	/*while (count++ < maxCount)
	{
		std::cout << "Main thread is running." << std::endl;
	}*/
	mutex = CreateMutex(NULL, false, NULL);
	Sleep(4000);
}

DWORD WINAPI Fun1Proc(LPVOID lpParamter)
{
	/*while (count++ < maxCount) {
		std::cout << "Thread1 is running." << std::endl;
	}*/
	while (true)
	{
		WaitForSingleObject(mutex, INFINITE);
		if (maxTicketNum > 0) {
			Sleep(1);
			std::cout << "Thread1 sells tickets: " << maxTicketNum-- << std::endl;
		}
		else {
			break;
		}
		ReleaseMutex(mutex);
	}

	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParamter)
{
	/*while (count++ < maxCount) {
		std::cout << "Thread2 is running." << std::endl;
	}*/

	while (true)
	{
		WaitForSingleObject(mutex, INFINITE);
		if (maxTicketNum > 0) {
			Sleep(1);
			std::cout << "Thread2 sells tickets: " << maxTicketNum-- << std::endl;
		}
		else {
			break;
		}
		ReleaseMutex(mutex);
	}

	return 0;
}

//#include <iostream>       // std::cout
//#include <atomic>         // std::atomic
//#include <thread>         // std::thread
//#include <vector>         // std::vector
//// a simple global linked list:
//struct Node {
//    int value; Node *next;
//};
//std::atomic<Node *> list_head(nullptr);
//void append(int val) {     // append an element to the list
//    std::cout << ' ' << val << std::endl;
//    Node *newNode = new Node{ val,list_head };
//    // next is the same as: list_head = newNode, but in a thread-safe way:
//    while (!list_head.compare_exchange_weak(newNode->next, newNode)) {
//    }
//    // (with newNode->next updated accordingly if some other thread just appended another node)
//}
//int main()
//{
//    // spawn 10 threads to fill the linked list:
//    std::vector<std::thread> threads;
//    for (int i = 0; i < 10; ++i) threads.push_back(std::thread(append, i));
//    for (auto &th : threads) th.join();
//
//    std::cout << '\n';
//    // print contents:
//    for (Node *it = list_head; it != nullptr; it = it->next)
//        std::cout << ' ' << it->value;
//    std::cout << '\n';
//    // cleanup:
//    Node *it; while (it = list_head) {
//        list_head = it->next; delete it;
//    }
//    return 0;
//}