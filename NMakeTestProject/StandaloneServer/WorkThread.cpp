#include "WorkThread.h"

WorkThread::WorkThread(ThreadFuncEmpty func, const std::string &inName):
	_workFunc(std::move(func)),
	_name(inName),
	_syncTool(1),
	_isJoined(false),
	_workThreadUniquePtr(nullptr)
{
}

WorkThread::~WorkThread()
{
	if (_workThreadUniquePtr && !_isJoined)
	{
		_workThreadUniquePtr->detach();
	}
}

struct WorkThreadData
{
	WorkThread::ThreadFuncEmpty _func;
	std::string _name;
	CountDownSyncTool *_syncTool;

	WorkThreadData(WorkThread::ThreadFuncEmpty func, const std::string &name, CountDownSyncTool *syncTool):
		_func(std::move(func)),
		_name(name),
		_syncTool(syncTool)
	{
	}
};

void ThreadEntryFunc(WorkThreadData *workThreadData)
{
	WorkThread::ThreadFuncEmpty workFunc = std::move(workThreadData->_func);
	workThreadData->_syncTool->CountDown();
	workFunc();
}

void WorkThread::Start()
{
	WorkThreadData data(_workFunc, _name, &_syncTool);
	_workThreadUniquePtr.reset(new std::thread(ThreadEntryFunc, &data));

	_syncTool.Wait();
}

void WorkThread::Join()
{
	_isJoined = true;
	_workThreadUniquePtr->join();
}
