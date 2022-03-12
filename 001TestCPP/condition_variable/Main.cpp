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
		cv.wait(lck);// 此处会释放lock，然后在cv上等待，直到其它线程通过cv.notify_xxx来唤醒当前线程，cv被唤醒后会再次对lock进行上锁，然后wait函数才会返回。
                     // wait返回后可以安全的使用mutex保护的临界区内的数据。此时mutex仍为上锁状态
	}

	std::cout << "thread: " << id << std::endl;
}

void go() {
	std::unique_lock<std::mutex> lck(mtx);//上面的wait会在条件变量上等待，并释放锁。这里获得锁后，notify_all，然后释放锁
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
