#include "Task.h"

Task::Task(int id):
	_taskID(id),
	status(TaskStatusEnum::Waiting)
{
}

Task::~Task()
{
}

void Task::Excute()
{
	status = TaskStatusEnum::Processing;
	std::cout << "Excute task id: " << _taskID << std::endl;
}
