#pragma once
#include <algorithm>
#include <limits>
using namespace std;

#define MAX_ELEMENT 200

// ���ĵ��� ���� 1���� �迭�� ����. ���� �켱���� ������ ����Ѵ�.
class MaxPriorityQueue
{
	int elem[MAX_ELEMENT];
	int size;

public:
	MaxPriorityQueue() : size(0) { fill(elem, elem + MAX_ELEMENT, 0); }

	void insert(int _elem)
	{
		elem[size++] = _elem;
	}

	int remove()
	{
		int maxElem = numeric_limits<int>::min();
		int removeIdx = 0;
		for (int i = 0; i < size; ++i) {
			if (elem[i] > maxElem) {
				maxElem = elem[i];
				removeIdx = i;
			}
		}
		for (int i = removeIdx; i < size - 1; ++i)
			elem[i] = elem[i + 1];
		--size;
		return maxElem;
	}

	int find()
	{
		int maxElem = numeric_limits<int>::min();
		for (int i = 0; i < size; ++i) {
			if (elem[i] > maxElem) {
				maxElem = elem[i];
			}
		}
		return maxElem;
	}

	void display()
	{
		for (int i = 0; i < size; ++i)
			printf("%3d ", elem[i]);
		printf("\n");
	}
};

// ���ĵ� ���� ����Ʈ�� �̿��Ͽ� �켱���� ť�� �����Ѵ�. �켱������ ���� ������ ����Ѵ�.
class Node
{
	int key;
	Node* link;

public:
	Node() : key(0), link(nullptr) {}
	Node(int item) : key(item), link(nullptr) {}

	int getKey() { return key; }
	void setKey(int _key) { key = _key; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};

class MinPriorityQueue
{
	Node* min;
	int size;

public:
	MinPriorityQueue() : size(0), min(nullptr) {}

	void insert(int item)
	{
		Node* newNode = new Node();
		Node* curNode = min;
		Node* preNode = nullptr;
		
		// ���� ��ġ�� ã�´�.
		while (curNode!= nullptr && curNode->getKey() <= item) {
			preNode = curNode;
			curNode = curNode->getLink();
		}

		// ù ��° ���ҿ� �� ��° ���� ���̰� ���� ��ġ�� ��
		if (preNode == nullptr) {
			newNode->setKey(item);
			newNode->setLink(min);
			min = newNode;
			++size;
		}
		else {
			preNode->setLink(newNode);
			newNode->setKey(item);
			newNode->setLink(curNode);
			++size;
		}
	}

	int remove()
	{
		if (isEmpty()) {
			printf("Queue is empty\n");
			return int{};
		}
		Node* newMin = min->getLink();
		int ret = newMin->getKey();
		delete min;
		min = newMin;
		--size;
		return ret;
	}

	int find()
	{
		if (isEmpty()) {
			printf("Queue is empty\n");
			return int{};
		}
		return min->getKey();
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT; }
	
	void display()
	{
		for (Node* p = min; p != nullptr; p = p->getLink())
			printf("%3d ", p->getKey());
		printf("\n");
	}
};
