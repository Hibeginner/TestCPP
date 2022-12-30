#include "UnityEditorMappingGenerator.h"
#include "FolderViewGenerator.h"
#include "ShowExeDependentDLL.h"
#include "CheckScreenLock.h"
#include "EXESignReader.h"

using namespace std;

class myclass
{
public:
	myclass(int a, int b) :first(a), second(b) {}
	int first;
	int second;
	bool operator < (const myclass &m)const
	{
		return first < m.first;
	}
};

bool less_second(const myclass &m1, const myclass &m2)
{
	return m1.second < m2.second;
}

void GenerateFoldView(int argc, const char *argv[])
{
	vector< myclass > vect;
	for (int i = 0; i < 10; i++)
	{
		myclass my(10 - i, i * 3);
		vect.push_back(my);
	}
	for (int i = 0; i < vect.size(); i++)
		cout << "(" << vect[i].first << "," << vect[i].second << ")\n";
	sort(vect.begin(), vect.end());
	cout << "after sorted by first:" << endl;
	for (int i = 0; i < vect.size(); i++)
		cout << "(" << vect[i].first << "," << vect[i].second << ")\n";
	cout << "after sorted by second:" << endl;
	sort(vect.begin(), vect.end(), less_second);
	for (int i = 0; i < vect.size(); i++)
		cout << "(" << vect[i].first << "," << vect[i].second << ")\n";

	/*UnityEditorMappingGenerator editorMappingGenerator(argc, argv);
	editorMappingGenerator.doGenerate();*/

	FolderViewGenerator folderViewGenerator(argc, argv);
	folderViewGenerator.doGenerate();
}

void ShowExeUsingDll(int argc, const char *argv[])
{
	if (argc < 2)
	{
		return;
	}
	const char *processChar = nullptr;
	for (int i = 0; i < argc; i++)
	{
		const char *tempArg = argv[i];
		std::cout << tempArg << std::endl;
		if (i == 1)
		{
			processChar = tempArg;
		}
	}

	ShowExeDependentDLL shower;
	shower.AdjustProcessTokenPrivilege();
	
	char *pEnd;
	DWORD processID(25888);//微信小程序的framework进程
	processID = strtoul(processChar, &pEnd, 10);
	shower.show(processID);
}

void ShowScreenLock() {
	CheckScreenLock checker;
	bool isLock = checker.IsSessionLocked();
}
void ShowExeSignInfo() {
	EXESignReader reader;
	reader.ShowSignInfo();
}

int main(int argc, const char *argv[])
{
	ShowScreenLock();
	ShowExeSignInfo();
	//GenerateFoldView(argc, argv);
	//ShowExeUsingDll(argc, argv);
	return 0;
}