#include "ClassReflectionTest.h"

ClassInfo CustomClassA::m_class_info_("CustomClassA", CustomClassA::CreateObject);// ����Ҫ��һ��������ǰ��ע�ᵽObject��

CustomClassA::CustomClassA():
	x(0),
	y(0)
{
}
