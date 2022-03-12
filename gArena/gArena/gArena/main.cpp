#include "ChainNode.h"
#include <vector>
#include <iostream>

ChainNode *reverse(ChainNode *headNode) {
	ChainNode *preNode = nullptr;
	ChainNode *phead = nullptr;
	ChainNode *temp = nullptr;
	phead = headNode;
	while (phead != nullptr) {
		temp = preNode;
		preNode = phead;
		phead = phead->next;//向下走一个
		preNode->next = temp;//指向之前的小的
	}
	return preNode;
}

ChainNode *mergeTwoChain(ChainNode *first, ChainNode *second) {
	ChainNode *newListHead = nullptr;
	ChainNode *newListRear = nullptr;
	
	if (first->value <= second->value) {//选一个小的做头结点
		newListHead = first;
		newListRear = first;
		first = first->next;
	}
	else
	{
		newListHead = second;
		newListRear = second;
		second = second->next;
	}

	while (first != nullptr && second != nullptr)
	{
		if (first->value <= second->value) {//向后走一个
			newListRear->next = first;
			newListRear = first;
			first = first->next;
		}
		else
		{
			newListRear->next = second;
			newListRear = second;
			second = second->next;
		}
	}

	if (first == nullptr) {
		newListRear->next = second;//接上
	}
	if (second == nullptr) {
		newListRear->next = first;
	}
	ChainNode *result = reverse(newListHead);

	return result;
}

std::vector<int> usedNumList;

bool match(int curPlayerNum, int playerNum) {
	if (curPlayerNum == playerNum) {
		return false;//如果相等
	}
	if (std::find(usedNumList.begin(), usedNumList.end(), playerNum) != usedNumList.end()) {
		return false;//如果后者用到过
	}
	
	std::cout << "(" << curPlayerNum << "," << playerNum << ")" << std::endl;
	return true;
}


void tryToMatchPlayer(int curPlayerNum, int playerNum, int &matchCount) {
	int matchedNum = 0;
	for (int i = 1; i <= playerNum; i++) {
		if (match(curPlayerNum, i)) {
			if (curPlayerNum == playerNum) {
				matchCount++;//该加一
			}
			matchedNum = i;

			usedNumList.push_back(i);
			if (curPlayerNum < playerNum) {
				tryToMatchPlayer(curPlayerNum + 1, playerNum, matchCount);
			}
		}

		if (/*i == playerNum &&*/ matchedNum > 0) {
			std::vector<int>::iterator iter = std::find(usedNumList.begin(), usedNumList.end(), matchedNum);
			if (iter != usedNumList.end()) {//剔除掉
				usedNumList.erase(iter);
				matchedNum = 0;
			}
		}
	}
	
}

void pickUpGame(int playerNum) {

	usedNumList.clear();
	int matchCount = 0;
	tryToMatchPlayer(1, playerNum, matchCount);


}




int main() {
	ChainNode *a1 = new ChainNode(1);
	ChainNode *a2 = new ChainNode(6);
	ChainNode *a3 = new ChainNode(11);
	a1->next = a2;
	a2->next = a3;

	ChainNode *a4 = new ChainNode(2);
	ChainNode *a5 = new ChainNode(7);
	ChainNode *a6 = new ChainNode(10);
	ChainNode *a7 = new ChainNode(12);
	a4->next = a5;
	a5->next = a6;
	a6->next = a7;

	mergeTwoChain(a1, a4);
	
	pickUpGame(4);
	return 0;
}

