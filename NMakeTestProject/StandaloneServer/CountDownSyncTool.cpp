#include "CountDownSyncTool.h"

CountDownSyncTool::CountDownSyncTool(int count):
	_count(count)
{
}

void CountDownSyncTool::Wait()
{
	std::unique_lock<std::mutex> lock(_mutex);
	if (_count > 0)
	{
		_conditionVariable.wait(lock);
	}
}

void CountDownSyncTool::CountDown()
{
	std::unique_lock<std::mutex> lock(_mutex);
	_count--;
	if (_count == 0)
	{
		_conditionVariable.notify_all();
	}
}
