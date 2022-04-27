#include "MockBuilder.h"

MockBuilder::MockBuilder():
	_processNum(4)
{
}

MockBuilder::~MockBuilder()
{
}

void MockBuilder::Build()
{
	int taskNum = 30;
	std::vector<Task *> taskList;
	std::vector<Task *> waitTaskList;
	for (int i = 0; i < taskNum; i++)
	{
		Task *taskPtr = new Task(i);
		taskList.push_back(taskPtr);

		waitTaskList.push_back(taskPtr);
	}

	std::vector<Task *> processingTaskList;
	std::vector<Task *> finishTaskList;
	std::unordered_map<Task * , WorkerThread *> workerThreadMap;
	int finishCount = 0;
	while (waitTaskList.size() > 0 || processingTaskList.size() > 0)
	{
		while (processingTaskList.size() < _processNum && waitTaskList.size() > 0)
		{
			Task *taskPtr = waitTaskList[waitTaskList.size() - 1];
			processingTaskList.push_back(taskPtr);
			waitTaskList.pop_back();

			WorkerThread *tempWorkThread = new WorkerThread(taskPtr, _finishTaskMutext, finishTaskList, _conditionVariable);
			tempWorkThread->Work();//启动线程执行
			workerThreadMap.emplace(taskPtr, tempWorkThread);
		}

		std::unique_lock<std::mutex> lock(_finishTaskMutext);//请求上锁
		if (finishTaskList.size() <= 0)
		{
			std::cout << "等待一个执行完!" << std::endl;
			_conditionVariable.wait(lock);//解锁，阻塞线程。等待notify，notify后上锁。
		}
		std::cout << "一次完成了：" << finishTaskList.size() << std::endl;
		for (auto finishTaskListIter = finishTaskList.begin(); finishTaskListIter != finishTaskList.end(); finishTaskListIter++)
		{
			finishCount++;
			Task *taskPtr = *finishTaskListIter;
			auto processingTaskListIter = processingTaskList.begin();
			while (processingTaskListIter != processingTaskList.end())
			{
				if (*processingTaskListIter == taskPtr)
				{
					processingTaskListIter = processingTaskList.erase(processingTaskListIter);
				}
				else
				{
					processingTaskListIter++;
				}
			}

			auto workerThreadMapIter = workerThreadMap.find(taskPtr);
			if (workerThreadMapIter != workerThreadMap.end())
			{
				workerThreadMapIter->second->Join();
				workerThreadMap.erase(workerThreadMapIter);
			}
		}

		finishTaskList.clear();
	}

	std::cout << "Excute task finish!" << std::endl;
}
