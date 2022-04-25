#pragma once
#include "CountDownSyncTool.h"
#include <string>
#include <functional>
#include <thread>
#include <memory>

class WorkThread
{
public:

	typedef std::function<void()> ThreadFuncEmpty;

	explicit WorkThread(ThreadFuncEmpty func, const std::string &inName = "unknow");
	~WorkThread();

	void Start();
	void Join();

private:
	CountDownSyncTool _syncTool;
	ThreadFuncEmpty _workFunc;
	std::string _name;
	bool _isJoined;
	std::unique_ptr<std::thread> _workThreadUniquePtr;
};

