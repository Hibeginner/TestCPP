#include "DynamicFieldReflection.h"
#include "StaticFieldReflection.h"
#include "ClassReflectionTest.h"
#include "MemberFuncTestClass.h"

#include "ReflectonTool/ClassObjectReflectionBaseObj.h"
#include "ReflectonTool/ClassFieldReflectionInfo.h"
#include "ReflectonTool/SelfReflectionTestClass.h"
#include "ReflectonTool/ClassFunctionReflectionInfo.h"

#include <iostream>
#include <typeinfo>

struct SimpleStruct
{
    bool bool_;
    int int_;
    double double_;
    std::string string_;
};

void DynamicFieldTest()
{
	auto bool_converter = [](bool *field, const std::string &name)
	{
		std::cout << std::boolalpha << name << ": " << *field << std::endl;
	};
	auto int_converter = [](int *field, const std::string &name)
	{
		std::cout << name << ": " << *field << std::endl;
	};
	auto double_converter = [](double *field, const std::string &name)
	{
		std::cout << std::fixed << name << ": " << *field << std::endl;
	};
	auto string_converter = [](std::string *field, const std::string &name)
	{
		std::cout << name << ": " << *field << std::endl;
	};

	StructValueConverter<SimpleStruct> converter;

	const bool SimpleStruct:: *testType1 = &SimpleStruct::bool_;
	converter.RegisterField(&SimpleStruct::bool_, "bool", ValueConverter<bool>(bool_converter));

	auto testType2 = &SimpleStruct::int_;
	converter.RegisterField(&SimpleStruct::int_, "int", ValueConverter<int>(int_converter));

	auto testType3 = &SimpleStruct::double_;
	converter.RegisterField(&SimpleStruct::double_, "double", ValueConverter<double>(double_converter));

	auto testType4 = &SimpleStruct::string_;
	converter.RegisterField(&SimpleStruct::string_, "string", ValueConverter<std::string>(string_converter));

	SimpleStruct simple{ true, 2, 2.0, "hello dynamic reflection" };
	converter(&simple);
	bool bResult = simple.*testType1;

	const char *typeInfo = typeid(testType3).name();
}


DEFINE_STRUCT_SCHEMA(SimpleStruct,
	DEFINE_STRUCT_FIELD(bool_, "bool"),
	DEFINE_STRUCT_FIELD(int_, "int"),
	DEFINE_STRUCT_FIELD(double_, "double"),
	DEFINE_STRUCT_FIELD(string_, "string"));

struct GenericFunctor
{
	// ... context data

	template <typename Field, typename Name>
	void operator()(Field &&field, Name &&name)
	{
		std::cout << std::boolalpha << std::fixed << name << ": " << field
			<< std::endl;
	}
};

namespace
{
	template <class... Fs>
	struct overload_set;

	template <class F1, class... Fs>
	struct overload_set<F1, Fs...> : F1, overload_set<Fs...>::type
	{
		typedef overload_set type;

		overload_set(F1 head, Fs... tail)
			: F1(head), overload_set<Fs...>::type(tail...) {}

		using F1::operator();
		using overload_set<Fs...>::type::operator();
	};

	template <class F>
	struct overload_set<F> : F
	{
		typedef F type;
		using F::operator();
	};

	template <class... Fs>
	typename overload_set<Fs...>::type overload(Fs... x)
	{
		return overload_set<Fs...>(x...);
	}

}  // namespace
void StaticFieldTest()
{
	ForEachField(SimpleStruct{ true, 1, 1.0, "hello static reflection" },
		[](auto &&field, auto &&name)
		{
			std::cout << std::boolalpha << std::fixed << name << ": "
				<< field << std::endl;
		});

	ForEachField(SimpleStruct{ true, 1, 1.0, "hello static reflection" },
		GenericFunctor{/* ... context data */ });

	ForEachField(SimpleStruct{ true, 1, 1.0, "hello static reflection" },
		overload(
			[](bool field, const char *name)
			{
				std::cout << "b " << std::boolalpha << name << ": "
					<< field << std::endl;
			},
			[](int field, const char *name)
			{
				std::cout << "i " << name << ": " << field << std::endl;
			},
				[](double field, const char *name)
			{
				std::cout << "d " << std::fixed << name << ": " << field
					<< std::endl;
			},
				[](const std::string &field, const char *name)
			{
				std::cout << "s " << name << ": " << field.c_str()
					<< std::endl;
			}));
}

void TestClassReflection()
{
	Object *obj = Object::CreateObject("CustomClassA");
	delete obj;
}

void TestClassField()
{
	CustomClassA p;
	p.x = 3;
	p.y = 5;
	CustomClassA *pPtr = &p;
	char *charPtr = (char *)pPtr;
	char *yPosPtr = charPtr + 8 + 4;//头上有8个字节，可能是虚表。拿到地址偏移
	int *yIntPtr = (int *)yPosPtr;//偏移后的地址转成指定类型
	*yIntPtr = 7;//然后设值


	//protobuf取地址偏移的方法，把地址空间0x10的内存，重新解释为类对象，然后取地址，算偏移
	uint32_t result = static_cast<::uint32_t>(
		reinterpret_cast<const char *>(&reinterpret_cast<const CustomClassA *>(16)->y)
		-
		reinterpret_cast<const char *>(16)
		);

	const CustomClassA *customClassAPtr1 = reinterpret_cast<const CustomClassA *>(16);
	const int *mockYIntPtr = &(customClassAPtr1->y);
	const char* mockYCharPtr = reinterpret_cast<const char *>(mockYIntPtr);

	const char *customClassAPtr2 = reinterpret_cast<const char *>(16);
	uint32_t calculatedResult = mockYCharPtr - customClassAPtr2;
}

void TestMemberFuncPtr()
{
	int *(CustomClassA:: * memberFuncPtr)(int) = &CustomClassA::GetIntPtr;//成员函数指针

	CustomClassA testA;
	int *resultPtr = (testA.*memberFuncPtr)(3);
}

void TestMemberFuncReflection()
{
	MemberFuncTestClassA a;
	std::vector<ClassMethod<MemberFuncTestClassA>> v;
	v.emplace_back("func", a, &MemberFuncTestClassA::func);
	v.emplace_back("fun2", a, &MemberFuncTestClassA::fun2);
	auto rd = v[0].Invoke<double>(5); // you have to specify return type
	auto ri = v[1].Invoke<int>('a'); // you have to specify return type
	std::cout << rd << " " << ri << "\n";
}

void TestSelfReflection()
{
	/*类反射*/
	ClassFieldReflectionInfo<SelfReflectionTestClass> fieldInfo;
	fieldInfo.RegistField("intValue", &SelfReflectionTestClass::intValue);
	fieldInfo.RegistField("strValue", &SelfReflectionTestClass::strValue);
	
	ClassObjectReflectionBaseObj* instance = ClassObjectReflectionBaseObj::CreateObject("SelfReflectionTestClass");

	SelfReflectionTestClass *childPtr = dynamic_cast<SelfReflectionTestClass *>(instance);


	/*类数据成员反射*/
	fieldInfo.SetFieldValue(childPtr, "intValue", 6);
	fieldInfo.SetFieldValue(childPtr, "strValue", std::string("abc"));//用属性偏移会更方便一些

	const char * typeChar = fieldInfo.GetFieldTypeByName("intValue");//用处可能就是把这个字符串显示在某个地方去
	
	std::string value = fieldInfo.GetFieldValue<std::string>(childPtr, "strValue");//get value接口。还是要指定返回值类型。用属性偏移会更方便一些


	/*类成员函数反射*/
	//ClassFunctionReflectionInfo<SelfReflectionTestClass> functionInfo("GetAString", &SelfReflectionTestClass::GetAString);
	//auto result = functionInfo.Invoke<std::string, const std::string &>(childPtr, std::string("kk"));//这里要指定返回值类型与入参类型。不灵活。UE用C#写的一套分析cpp文件生成反射信息还是有必要的
	ClassFunctionReflectionInfo<SelfReflectionTestClass> functionInfo;
	functionInfo.RegistFunction("GetAString", &SelfReflectionTestClass::GetAString);
	auto result = functionInfo.Invoke<std::string, const std::string &>(childPtr, "GetAString", std::string("kk"));


	auto funcPtr = &SelfReflectionTestClass::GetAString;//记一个函数指针和类的映射会更直接吧
	auto result1 = (childPtr->*funcPtr)(std::string("mm"));
	std::unordered_map<std::string, decltype(&SelfReflectionTestClass::GetAString)> funcPtrMap;
	funcPtrMap.emplace("SelfReflectionTestClass::GetAString", funcPtr);
	auto funcPtrInMap = funcPtrMap["SelfReflectionTestClass::GetAString"];
	auto result2 = (childPtr->*funcPtrInMap)(std::string("pp"));//根据类对象，从指针map里拿。但是仍然要提供返回值类型和入参类型
}

int main()
{
	//DynamicFieldTest();
	//StaticFieldTest();
	//TestClassReflection();
	//TestClassField();
	//TestMemberFuncPtr();
	//TestMemberFuncReflection();
	TestSelfReflection();

    return 0;
}