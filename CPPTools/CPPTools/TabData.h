#pragma once

#ifndef TabData_H
#define TabData_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class TabData
{
public:
	std::vector<std::wstring> dirVector;
	std::wstring selfName;
	std::wstring mappingName;
};

class TabDataTreeNode
{
public:
	std::wstring treeName;
	std::vector<TabDataTreeNode> leafsVector;
	TabData tabData;
	/*bool operator=(const TabDataTreeNode &other)const
	{
		if (other.treeName != treeName)
		{
			return false;
		}
		if (leafsVector.size() != other.leafsVector.size())
		{
			return false;
		}
		return true;
	}*/
	bool operator<(const TabDataTreeNode &other)const
	{
		
		return leafsVector.size() < other.leafsVector.size();
	}

	bool operator>(const TabDataTreeNode &other)const
	{

		return leafsVector.size() > other.leafsVector.size();
	}
};



class TabDataTree
{
public:
	TabDataTreeNode root;
	std::wstring logStr;
	void addToTree(TabData &tabData);

	void logTree();
	void logTreeByNode(TabDataTreeNode &node, int deep);
};

#endif