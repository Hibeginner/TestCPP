#include "WorkerThread.h"

WorkerThread::WorkerThread(Task *taskPtr, std::mutex& mutex, std::vector<Task *> &finishTaskList,
	std::condition_variable &conditionVariable):
	_taskPtr(taskPtr),
	_mutex(mutex),
	_finishTaskList(finishTaskList),
	_conditionVariable(conditionVariable),
	_workThread(nullptr)
{
}

WorkerThread::~WorkerThread()
{
}

void WorkerThread::Work()
{
	_workThread.reset(new std::thread(&WorkerThread::WorkEntry, this));
}

void WorkerThread::Join()
{
	if (_workThread)
	{
		_workThread->join();
	}
}

void WorkerThread::WorkEntry()
{
	if (_taskPtr)
	{
		_taskPtr->Excute();
		_taskPtr->status = Task::TaskStatusEnum::Finish;
	}

	std::lock_guard<std::mutex> lock(_mutex);
	_finishTaskList.push_back(_taskPtr);
	
	_conditionVariable.notify_one();
}
