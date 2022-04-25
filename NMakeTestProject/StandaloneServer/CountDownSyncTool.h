#pragma once
#include <mutex>
#include <condition_variable>

class CountDownSyncTool
{
public:
    explicit CountDownSyncTool(int count);

    void Wait();

    void CountDown();

private:
    int _count;
    std::mutex _mutex;
    std::condition_variable _conditionVariable;
};

