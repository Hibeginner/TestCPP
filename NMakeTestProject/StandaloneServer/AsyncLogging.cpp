#include "AsyncLogging.h"

AsyncLogging::AsyncLogging(const std::string &name, int size, int flushInterval):
	_name(name),
	_flushInterval(flushInterval),
	_rollSize(size),
	_workThread(std::bind(&AsyncLogging::WriteLog, this), "AsyncLogging"),
	_syncTool(1),
	_isRunning(false)
{
}

AsyncLogging::~AsyncLogging()
{
	if (_isRunning)
	{
		Stop();
	}
}

void AsyncLogging::Append(const char *log, int length)
{
}

void AsyncLogging::Start()
{
	_isRunning = true;
	_workThread.Start();
	_syncTool.Wait();
}

void AsyncLogging::Stop()
{
	_isRunning = false;
	_workThread.Join();
}

void AsyncLogging::WriteLog()
{
	//_syncTool.CountDown();
	std::cout << "start" << std::endl;
	int counting = 0;
	while (_isRunning)
	{
		counting++;
		std::cout << "counting: " << counting << std::endl;
		Sleep(2000);
		if (counting > 2)
		{
			_syncTool.CountDown();
		}
	}
	std::cout << "finish" << std::endl;
}
