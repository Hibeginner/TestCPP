#include <fstream>
#include "Point.h"
#include <iostream>
#include "TestClass.h"
#include <memory>
#include <stdexcept>
#include <map>
#include <functional>
using namespace std;

#ifndef TEST_MULTI_INCLUDE
#define TEST_MULTI_INCLUDE 102
#endif // !TEST_MULTI_INCLUDE

#define PI 3.1415926

Point* pointerArr[5];

void testPointer()
{
	//throw std::runtime_error("xxx");//throw的过程与调用相反，会先检查自己有没有catch住，再回溯调用者，逐层检查。（如果没有找到catch块，那么后续行为与系统有关。一般情况下会导致程序异常退出。但是现在来看，win系统没有异常退出）
	Point* testPoint = new Point();
	pointerArr[0] = testPoint;

}

Point genPoint() {//局部变量会先调用移动构造，或赋值构造，创建一个临时对象作为返回。然后销毁掉临时对象
	Point p(1, 3);
	return p;
}

Point &getRefferencePoint() {//返回引用时，不会调用任何构造函数。但是局部变量p已被销毁
	Point p(1, 3);
	return p;
}

int Paritition1(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high) //快排母函数
{
	if (low < high) {
		int pivot = Paritition1(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}

struct divide {
	int operator()(int a1, int a2) {
		return a1 / a2;
	}
	static int matchFun(int a1, int a2) {//静态成员函数，才是直接可调用的函数。普通成员函数，有个隐式的this指针，必须实例化后才能调用
		return a1 + a2;
	}
};
class divideClass {
public:
	int operator()(int a1, int a2) {
		return a1 / a2;
	}
};

void processSharedPtr(const std::shared_ptr<TestClass> &sharedP) {

}

void testRightReff(Point && pRef){
	int a = 1;
}

union testUnion
{
	int intValue;
	Point pointValue;
};

int main(void) {
	//testUnion aUnion = {2};//因为point定义了自己的构造函数或析构函数，所以无法实例化这个union。除非这个union定义自己的构造和析构函数。可以理解为point在union里是以指针形式存在的，编译器无法自动析构它。（我觉得编译器还能再优化一下）
	//ChildTestClass childTestClass;
	//childTestClass.saySomething();
	//childTestClass.notOverrideFunc();

	//TestClass *testClassPtr = &childTestClass;
	//testClassPtr->saySomething();
	//testClassPtr->notOverrideFunc();//调用父类的

	/*TestClass testClass = static_cast<TestClass>(childTestClass);
	testClass.saySomething();//强制类型转换后，调用父类的*/

	/*TestClass testClass = static_cast<TestClass>(childTestClass);//实际上调用了赋值构造
	ChildTestClass childClassCastedPtr = static_cast<ChildTestClass>(testClass);
	childClassCastedPtr.saySomething();*/
	/*TestClass *testClass = dynamic_cast<TestClass*>(&childTestClass);
	testClass->saySomething();//调用子类的*/
	/*TestClass *testClass = dynamic_cast<TestClass *>(&childTestClass);
	ChildTestClass *childTestClassPtr = dynamic_cast<ChildTestClass *>(testClass);
	childTestClassPtr->saySomething();//调用子类的*/

	//const std::shared_ptr<TestClass> &baseClassSharedPtrRef = std::make_shared<ChildTestClass>();
	size_t childTestClassSize = sizeof(ChildTestClass);
	std::shared_ptr<ChildTestClass> sharedP(new ChildTestClass);
	processSharedPtr(sharedP);

	const std::shared_ptr<TestClass> &baseClassSharedPtrRef = std::make_shared<ChildTestClass>();

	std::map<std::string, std::function<int(int, int)>> calculateOps;
	calculateOps.insert({ "/", divide() });
	calculateOps.insert({ "m", divide::matchFun });
	calculateOps.insert({ "/", divideClass() });
	divide divideInst;
	int divideResult = divideInst(3, 2);

	int arr[8] = {22,66,44,99,33,77,11,55};
	QuickSort(arr, 0, 7);

	Point &&rightRefferenceP = genPoint();
	Point leftP = Point();
	testRightReff(std::move(leftP));
	//Point valueP = genPoint();
	//Point &refferenceP = genPoint();
	//Point &refferenceP = getRefferencePoint();
	/*std::ofstream outFile("hh.bin", std::ofstream::binary);
	int a = 264;
	int size = sizeof(a);
	char * ap = (char *)&a;
	outFile.write(ap, size);
	outFile.close();

	int toRestore = 0;
	std::ifstream inFile("hh.bin", std::ofstream::binary);
	inFile.read((char *)&toRestore, sizeof(int));
	inFile.close();*/
	/*TestClass tc = TestClass();
	TestClass tc2;
	std::vector<TestClass> t(2);
	TestClass tArr[2];*/
	/*Point *forUniqueP;
	{
		std::unique_ptr<Point> uniquePointer;
		forUniqueP = new Point();
		uniquePointer.reset(forUniqueP);
	}*/
	
	constexpr std::string::size_type npoValue = std::string::npos;

	int a = 6;
	int &r = a;
	int *p = &a;
	int x = r;

	int b = PI;

	int test[4] = {1, 2, 3, 4};
	int(*testP)[4];
	testP = &test;

	char * followMe = "Follow me";
	char * basic = "BASIC";
	char * greatWall = "Great Wall";

	char * name[] = {followMe, basic, greatWall};

	struct Student
	{
		int num;//4
		char name[20];//20
		char sex;//1 + 3
		int age;//4
		float score;//4
		char addr[30];//30 + 2，
	};//结构体最长数据类型为int，4字节。那么就以4字节对齐。
	Student student1 = {1.0, "LL", 'M', 22, 88, "abcd"};
	int doubleSize = sizeof(double);
	int intSize = sizeof(int);
	int charSize = sizeof(char);
	int floatSize = sizeof(float);
	int size = sizeof(Student);
	int stdu1Size = sizeof(student1);
	try
	{
		testPointer();
	}
	catch (const std::exception &)
	{
		int aaaa = 1;
	}
	//testPointer();
	
	
	Point* pointArr = new Point[15];

	/*int sum = 0;
	int value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;*/
	std::cout << TEST_MULTI_INCLUDE << std::endl;

	std::ofstream outFile("int.bin", std::ofstream::binary);
	/*int writeA = 12;
	int writeASize = sizeof(writeA);*/
	char writeChar = 'a';
	int writeASize = sizeof(writeChar);
	char *ap = (char *)&writeChar;
	outFile.write(ap, writeASize);
	outFile.close();

	double doubleValue = 3.14;
	const int& refInt = doubleValue;//从“double”转换到“const int”，可能丢失数据。实际上是绑定到了一个临时量上
	//int& nonConstRefInf = doubleValue;//非法，非常量引用，不能绑定到临时量上

	extern int testGlobalFunc(int a, int b);
	extern int globalInt;

	int result = testGlobalFunc(globalInt, 5);

	int tempInt = Point::staticInt;

	Point::staticVector.push_back("44");

	int intArr[4] = {1,2,3,4};
	int(*parray)[4] = &intArr;
	size_t index = 3;

	const char *charPointer = "abcd";
	std::string convertedStr = static_cast<std::string>(charPointer);//字符串字面值转string，估计有拷贝构造
	convertedStr = "123";

	int testInt = 2;
	const int *intPointer = &testInt;
	//std::string convertedIntStr = static_cast<std::string>(intPointer);//错误：不存在从int *到string的构造函数

	int sw1;
	int sw2;
	switch (testInt)
	{
	case 1:
		sw1 = 1;
		break;
	case 2:
		sw2 = 21;
		break;
	case 11:
		sw1 = 1;
		break;
	case 222:
		sw2 = 21;
		break;
	case 33:
		sw1 = 1;
		break;
	case 56:
		sw2 = 21;
		break;
	case 55:
		sw1 = 1;
		break;
	case 90:
		sw2 = 21;
		break;
	case 10000:
		sw1 = 1;
		break;
	case 2000:
		sw2 = 21;
		break;
	case 56082:
		sw1 = 1;
		break;
	case 23548:
		sw2 = 21;
		break;
	case 5:
		sw1 = 1;
		break;
	case 50:
		sw2 = 21;
		break;
	default:
		break;
	}

	int testI = 3;
	const int &testIRef = testI;
	testI = 5;
	//testIRef = 3;

	return 0;
}