#include "Main.h"

#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
	std::cout << "print_id start: " << id << std::endl;
	std::unique_lock<std::mutex> lck(mtx);
	while (!ready) {
		std::cout << "wait loop: " << id << std::endl;
		cv.wait(lck);// �˴����ͷ�lock��Ȼ����cv�ϵȴ���ֱ�������߳�ͨ��cv.notify_xxx�����ѵ�ǰ�̣߳�cv�����Ѻ���ٴζ�lock����������Ȼ��wait�����Ż᷵�ء�
                     // wait���غ���԰�ȫ��ʹ��mutex�������ٽ����ڵ����ݡ���ʱmutex��Ϊ����״̬
	}

	std::cout << "thread: " << id << std::endl;
}

void go() {
	std::unique_lock<std::mutex> lck(mtx);//�����wait�������������ϵȴ������ͷ���������������notify_all��Ȼ���ͷ���
	ready = true;
	std::cout << "go!!!" << std::endl;
	cv.notify_all();
}

int main()
{
	std::thread threads[10];

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "threads: " << i << " created" << std::endl;
		threads[i] = std::thread(print_id, i);
	}
	std::cout << "10 threads ready to race..." << std::endl;

	go();

	for (auto& th : threads) {
		th.join();
	}

	return 0;
}
