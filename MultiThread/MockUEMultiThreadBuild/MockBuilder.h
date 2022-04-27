#pragma once
#include "WorkerThread.h"
#include "Task.h"
#include <vector>
#include <mutex>
#include <condition_variable>

class MockBuilder
{
public:
	MockBuilder();
	~MockBuilder();
	void Build();
private:
	std::mutex _finishTaskMutext;
	int _processNum;
	std::condition_variable _conditionVariable;
};

