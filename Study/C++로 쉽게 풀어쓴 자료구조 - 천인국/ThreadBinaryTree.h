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
			printf("   ������ ����Ʈ�� Inorder(): ");
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
		// �Ķ���ͷ� ���� p�� ������ ��ũ ���� ���Ѵ�. �� ���� �������� ����, ������ �ڽ��� ���� �ִ�.
		// q�� ������ ��ũ��! ������ �ڽ��� ����, �������� ���� �ִ�!
		ThreadedBinNode* q = p->getRight();

		// ������ ��ũ�� nullptr�� ���� ���� ���� ������ �� �Ʒ��ִ� �ܸ������ �����̴�. �� ���� ��ȸ���� ���� ���������� �湮�� ����̴�.
		// �� �� �� �Լ��� nullptr�� �����ϰ�, threadedInorder()�Լ��� while���� ����� ������ �Ǿ�, ���� ��ȸ�� ������.
		// p->bThread�� ���� ������ ��ũ�� �ڽ��� �ƴϰ� �������̹Ƿ� �ٷ� �����Ѵ�. (Ÿ�� ������ �ڽ��� ����)
		if (q == nullptr || p->bThread) return q;

		// ������ �ڽ��̶��, ���� ��ȸ�̹Ƿ� �� ������ ����� �ڽĵ� �� ���� �Ʒ� �� �ڽ� ��带 ���ؾ� �Ѵ�.
		while (q->getLeft() != nullptr) q = q->getLeft();
		return q;
	}
};