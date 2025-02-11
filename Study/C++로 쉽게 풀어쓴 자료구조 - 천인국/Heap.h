#pragma once
#include <cstdio>

class HeapNode 
{
	int key;
public:
	HeapNode(int k = 0) : key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { printf("%4d", key); }
};

#define MAX_ELEMENT 200

class MaxHeap
{
	HeapNode node[MAX_ELEMENT];
	int size;

public:
	MaxHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key)
	{
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key > getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove() 
	{ 
		if (isEmpty()) return HeapNode{};
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		/*	만약 child가 노드의 개수보다 크면 종료함
		*	현재 child는 레벨의 왼쪽 자식이다.
			만약 (child가 노드의 개수보다 작고) 부모의 왼쪽자식이 부모의 오른쪽 자식보다 작다면
			child 개수 하나 늘림-> child를 오른쪽 자식으로 설정한다는 의미. 그 이유는 부모의 오른쪽 자식이 더 크므로 더 큰 자식과 교환할 꺼임.
			왼쪽이 더 크면 child 그냥 냅둬서 왼쪽 자식으로 유지
			만약 마지막 노드가 차일드보다 크다면 break. 그냥 root자리에 넣을꺼임. 마지막 노드가 제일 크기 때문에

			부모에 더 큰 자식을 넣고
			부모의 인덱스를 child의 인덱스로 바꾼다.(더 큰 자식으로)
			child는 다음 레벨로 건너뛴다.
		*/
		while (child <= size) {
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
				child++;
			if (last.getKey() >= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}

	HeapNode find() { return node[1]; }

	void display()
	{
		for (int i = 1, level = 1; i <= size; ++i) {
			if (i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n------------------------------------");
	}
};

class MinHeap
{
	HeapNode node[MAX_ELEMENT];
	int size;

public:
	MinHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key)
	{
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove()
	{
		if (isEmpty()) return HeapNode{};
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}

	HeapNode find() { return node[1]; }

	void display()
	{
		for (int i = 1, level = 1; i <= size; ++i) {
			if (i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n------------------------------------");
	}
};