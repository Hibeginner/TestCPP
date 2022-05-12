#include "ClassReflectionTest.h"

ClassInfo CustomClassA::m_class_info_("CustomClassA", CustomClassA::CreateObject);// 最重要的一步，将当前类注册到Object中

CustomClassA::CustomClassA():
	x(0),
	y(0)
{
}
