#pragma once
#include <iostream>

class Task
{
public:
	Task(int id);
	~Task();
	void Excute();

	enum class TaskStatusEnum
	{
		Waiting,
		Processing,
		Finish
	};

	TaskStatusEnum status;
private:
	int _taskID;
};

