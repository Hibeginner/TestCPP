#include "DynamicFieldReflection.h"
#include "StaticFieldReflection.h"
#include "ClassReflectionTest.h"
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
	converter.RegisterField(&SimpleStruct::bool_, "bool",
		ValueConverter<bool>(bool_converter));
	auto testType2 = &SimpleStruct::int_;
	converter.RegisterField(&SimpleStruct::int_, "int",
		ValueConverter<int>(int_converter));
	auto testType3 = &SimpleStruct::double_;
	converter.RegisterField(&SimpleStruct::double_, "double",
		ValueConverter<double>(double_converter));
	auto testType4 = &SimpleStruct::string_;


	converter.RegisterField(&SimpleStruct::string_, "string",
		ValueConverter<std::string>(string_converter));

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
	Object *obj = Object::CreateObject("A");
	delete obj;
}

int main()
{
	//DynamicFieldTest();
	//StaticFieldTest();
	TestClassReflection();

    return 0;
}