#include "AsyncLogging.h"

std::unique_ptr<AsyncLogging> g_asyncLogging;
void SetLogging(const std::string &arg)
{
	g_asyncLogging.reset(new AsyncLogging(arg, 50000));
	g_asyncLogging->Start();
}

int main()
{
	SetLogging("123");

	return 0;
}