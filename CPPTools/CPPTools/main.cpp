#include "UnityEditorMappingGenerator.h"
#include "FolderViewGenerator.h"
#include "ShowExeDependentDLL.h"

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

void ShowExeUsingDll()
{
	ShowExeDependentDLL shower;
	shower.AdjustProcessTokenPrivilege();
	//tasklist
	DWORD processID(17784);//微信小程序的framework进程
	shower.show(processID);
}

int main(int argc, const char *argv[])
{
	//GenerateFoldView(argc, argv);
	ShowExeUsingDll();
	return 0;
}