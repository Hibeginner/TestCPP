#pragma once
enum CellTypeEnum
{
	nomarl,
	door
};
class ChainNode
{
public:
	ChainNode(int);
	ChainNode *next;
	int value;
	CellTypeEnum type;
private:
};

