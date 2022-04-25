#pragma once
#include <string>
#include <thread>
#include <atomic>
#include "WorkThread.h"
#include "CountDownSyncTool.h"
#include <iostream>
#include <windows.h>

class AsyncLogging
{
public:
	AsyncLogging(const std::string &name, int size, int flushInterval = 3);
	~AsyncLogging();

	void Append(const char *log, int length);
	void Start();
	void Stop();

private:
	void WriteLog();
	std::string _name;
	int _flushInterval;
	std::atomic<bool> _isRunning;
	const int _rollSize;
	WorkThread _workThread;
	CountDownSyncTool _syncTool;
};

