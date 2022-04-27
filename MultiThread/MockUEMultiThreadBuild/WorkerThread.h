#pragma once
#include "Task.h"
#include <thread>
#include <memory>
#include <mutex>
#include <vector>
#include <unordered_map>
#include <condition_variable>

class WorkerThread
{
public:
	WorkerThread(Task *taskPtr, std::mutex &mutex, std::vector<Task *> &finishTaskList, std::condition_variable &conditionVariable);
	~WorkerThread();

	void Work();
	void Join();
private:
	void WorkEntry();
	Task *_taskPtr;
	std::mutex &_mutex;
	std::vector<Task *> &_finishTaskList;
	std::condition_variable &_conditionVariable;
	std::unique_ptr<std::thread> _workThread;
};

