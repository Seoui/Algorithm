#pragma once
#include <cstdio>

class ThreadedBinNode 
{
	int data;
	ThreadedBinNode* left;
	ThreadedBinNode* right;

public:
	bool bThread;
	ThreadedBinNode(int val, ThreadedBinNode* l, ThreadedBinNode* r, bool bTh)
		: data(val), left(l), right(r), bThread(bTh) {}

	int getData() { return data; }
	void setRight(ThreadedBinNode* r) { right = r; }
	void setLeft(ThreadedBinNode* l) { left = l; }
	ThreadedBinNode* getRight() { return right; }
	ThreadedBinNode* getLeft() { return left; }
};

class ThreadedBinTree
{
	ThreadedBinNode* root;

public:
	ThreadedBinTree() : root(nullptr) {}
	void setRoot(ThreadedBinNode* node) { root = node; }
	bool isEmpty() { return root == nullptr; }

	void threadedInorder()
	{
		if (!isEmpty()) {
			printf("   스레드 이진트리 Inorder(): ");
			ThreadedBinNode* q = root;
			while (q->getLeft())
				q = q->getLeft();
			do {
				printf("[%c] ", q->getData());
				q = findSuccessor(q);
			} while (q);
			printf("\n");
		}
	}

	ThreadedBinNode* findSuccessor(ThreadedBinNode* p)
	{
		// 파라미터로 들어온 p의 오른쪽 링크 값을 구한다. 이 값은 스레드일 수도, 오른쪽 자식일 수도 있다.
		// q는 오른쪽 링크다! 오른쪽 자식일 수도, 스레드일 수도 있는!
		ThreadedBinNode* q = p->getRight();

		// 오른쪽 링크가 nullptr을 갖는 경우는 가장 오른쪽 끝 아래있는 단말노드일 때만이다. 즉 중위 순회에서 가장 마지막으로 방문될 노드이다.
		// 이 때 이 함수는 nullptr을 리턴하고, threadedInorder()함수의 while문이 종료될 조건이 되어, 중위 순회가 끝난다.
		// p->bThread인 경우는 오른쪽 링크가 자식이 아니고 스레드이므로 바로 리턴한다. (타고 내려갈 자식이 없다)
		if (q == nullptr || p->bThread) return q;

		// 오른쪽 자식이라면, 중위 순회이므로 이 오른쪽 노드의 자식들 중 왼쪽 아래 끝 자식 노드를 구해야 한다.
		while (q->getLeft() != nullptr) q = q->getLeft();
		return q;
	}
};