#include "TabData.h"

void TabDataTree::addToTree(TabData &tabData)
{
	TabDataTreeNode *searchNode = &root;
	int folderDeep = 0;

	int dirDeep = tabData.dirVector.size();
	for (auto folderPathIter = tabData.dirVector.begin(); folderPathIter != tabData.dirVector.end(); folderPathIter++)
	{
		std::wstring folderName = *folderPathIter;
		bool shouldCreateNode = true;
		if (searchNode->leafsVector.size() > 0)
		{
			for (auto leafsNodeIter = searchNode->leafsVector.begin(); leafsNodeIter != searchNode->leafsVector.end(); leafsNodeIter++)
			{
				if (folderName.compare(leafsNodeIter->treeName) == 0)
				{
					shouldCreateNode = false;
					searchNode = &(*leafsNodeIter);
					break;
				}
			}
		}
		else
		{
			shouldCreateNode = true;
		}
		if (shouldCreateNode)
		{
			TabDataTreeNode leafNode;
			leafNode.treeName = folderName;
			searchNode->leafsVector.push_back(leafNode);
			int leafsVectorSize = searchNode->leafsVector.size();
			TabDataTreeNode &insertedTreeNode = searchNode->leafsVector[leafsVectorSize - 1];
			searchNode = &insertedTreeNode;
		}
		if (folderDeep == dirDeep - 1)
		{
			TabDataTreeNode endLeaf;
			endLeaf.treeName = tabData.selfName;
			endLeaf.tabData = tabData;
			searchNode->leafsVector.push_back(endLeaf);
		}
		folderDeep++;
	}
}

void TabDataTree::logTree()
{
	logStr = L"";
	logTreeByNode(root, 0);
	int a = 1;
}

bool lessCompare(const TabDataTreeNode &m1, const TabDataTreeNode &m2)
{
	return m1 < m2;
}

bool greaterCompare(const TabDataTreeNode &m1, const TabDataTreeNode &m2)
{
	return m1 > m2;
}

void TabDataTree::logTreeByNode(TabDataTreeNode &node, int deep)
{
	logStr += L"\n";
	for (int i = 0; i < deep; i++)
	{
		logStr += L"\t";
	}
	logStr += node.treeName;

	if (node.leafsVector.size() > 0)
	{
		std::vector<TabDataTreeNode> &sortRef = node.leafsVector;
		/*std::sort(sortRef.begin(), sortRef.end(), [](TabDataTreeNode a, TabDataTreeNode b) {
			return a < b;
			});*/
		std::sort(sortRef.begin(), sortRef.end(), greaterCompare);
		//std::sort(sortRef.begin(), sortRef.end());
		for (int i = 0; i < sortRef.size(); i++)
		{
			logTreeByNode((sortRef[i]), deep + 1);
		}
	}
	else
	{
		if (node.tabData.mappingName.compare(L"") != 0 && node.tabData.selfName.compare(L"") != 0)
		{
			logStr += L"\t" + node.tabData.mappingName;
		}
	}
}