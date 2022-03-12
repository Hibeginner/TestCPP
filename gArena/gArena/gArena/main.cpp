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
		phead = phead->next;//������һ��
		preNode->next = temp;//ָ��֮ǰ��С��
	}
	return preNode;
}

ChainNode *mergeTwoChain(ChainNode *first, ChainNode *second) {
	ChainNode *newListHead = nullptr;
	ChainNode *newListRear = nullptr;
	
	if (first->value <= second->value) {//ѡһ��С����ͷ���
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
		if (first->value <= second->value) {//�����һ��
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
		newListRear->next = second;//����
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
		return false;//������
	}
	if (std::find(usedNumList.begin(), usedNumList.end(), playerNum) != usedNumList.end()) {
		return false;//��������õ���
	}
	
	std::cout << "(" << curPlayerNum << "," << playerNum << ")" << std::endl;
	return true;
}


void tryToMatchPlayer(int curPlayerNum, int playerNum, int &matchCount) {
	int matchedNum = 0;
	for (int i = 1; i <= playerNum; i++) {
		if (match(curPlayerNum, i)) {
			if (curPlayerNum == playerNum) {
				matchCount++;//�ü�һ
			}
			matchedNum = i;

			usedNumList.push_back(i);
			if (curPlayerNum < playerNum) {
				tryToMatchPlayer(curPlayerNum + 1, playerNum, matchCount);
			}
		}

		if (/*i == playerNum &&*/ matchedNum > 0) {
			std::vector<int>::iterator iter = std::find(usedNumList.begin(), usedNumList.end(), matchedNum);
			if (iter != usedNumList.end()) {//�޳���
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

