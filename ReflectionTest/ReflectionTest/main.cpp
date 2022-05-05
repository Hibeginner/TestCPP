#include "DynamicReflection.h"
#include <iostream>
#include <typeinfo>

struct SimpleStruct
{
    bool bool_;
    int int_;
    double double_;
    std::string string_;
};

int main()
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
    return 0;
}