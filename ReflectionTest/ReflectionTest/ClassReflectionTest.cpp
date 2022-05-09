#include "ClassReflectionTest.h"

ClassInfo A::m_class_info_("A", A::CreateObject);// 最重要的一步，将当前类注册到Object中