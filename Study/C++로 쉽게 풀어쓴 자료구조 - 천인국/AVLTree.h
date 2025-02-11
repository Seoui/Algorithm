#pragma once
#include "BinarySearchTree.h"

// AVL Ʈ���� ���� Ž�� Ʈ���� �� �����̴�.
// ���� Ž�� Ʈ���� ��� ������ �����Ѵ�.
class AVLTree : public BinSrchTree
{
public:
	// ����� �����μ��� ��ȯ
	// �����μ�: (���� �ڽ��� ���� - ������ �ڽ��� ����)
	int getHeightDiff(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		int hLeft = getHeight_t(node->getLeft());
		int hRight = getHeight_t(node->getRight());
		return hLeft - hRight;
	}

	// LLȸ��(�����ʿ��� �������� ȸ���Ѵٰ� ����. �ð������)
	BinaryNode* rotateLL(BinaryNode* parent)
	{
		// ���� �ڽ��� ��Ʈ�� �ö�;� �ϹǷ�
		BinaryNode* child = parent->getLeft();
		// ��Ʈ�� ���� �ڽ��� ������ ���� �ڽ��� ������ �ڽ��� ��.
		parent->setLeft(child->getRight());
		// ���� �ڽ��� ������ �ڽ��� ���� ��Ʈ�� ����
		child->setRight(parent);
		// ���Ӱ� ���ŵ� ��Ʈ ��ȯ
		return child;
	}

	// RRȸ��(���ʿ��� ���������� ȸ���Ѵٰ� ����. �ݽð������)
	BinaryNode* rotateRR(BinaryNode* parent)
	{
		// ������ �ڽ��� ��Ʈ�� �ö�;� �ϹǷ�
		BinaryNode* child = parent->getRight();
		// ��Ʈ�� ������ �ڽ��� ������ ������ �ڽ��� ���� �ڽ��� ��.
		parent->setRight(child->getLeft());
		// ������ �ڽ��� ���� �ڽ��� ���� ��Ʈ�� ����
		child->setLeft(parent);
		// ���Ӱ� ���ŵ� ��Ʈ ��ȯ
		return child;
	}
	// RLȸ��(LLȸ�� �� RRȸ��)
	BinaryNode* rotateRL(BinaryNode* parent)
	{
		// ó�� LLȸ���� ������ �ڽ��� ��Ʈ�� ��� LLȸ�� �Ѵ�.
		BinaryNode* child = parent->getRight();
		parent->setRight(rotateLL(child));
		// �� ���� ��Ʈ�� RRȸ��
		return rotateRR(parent);
	}
	// LRȸ��(RRȸ�� �� LLȸ��)
	BinaryNode* rotateLR(BinaryNode* parent)
	{
		// ó�� RRȸ���� ���� �ڽ��� ��Ʈ�� ��� RRȸ�� �Ѵ�.
		BinaryNode* child = parent->getLeft();
		parent->setLeft(rotateRR(child));
		// �� ���� ��Ʈ�� LLȸ��
		return rotateLL(parent);
	}
	// Ʈ���� ����Ʈ���� �����
	BinaryNode* reBalance(BinaryNode* parent)
	{
		int hDiff = getHeightDiff(parent);
		// hDiff�� 1���� ũ�ٸ� ���� ����Ʈ���� �ʹ� ���ٴ� ���
		if (hDiff > 1) {
			// �׷� ���� ����Ʈ������ �ٽ� �����μ��� ���ؼ� 0���� ũ�ٴ� ����
			// ���� ����Ʈ���� ���� ����Ʈ���� �� ũ�ٴ� ���. LLȸ��
			if (getHeightDiff(parent->getLeft()) > 0)
				parent = rotateLL(parent);
			// ���� ����Ʈ���� ������ ����Ʈ���� �� ũ��. RRȸ��
			else
				parent = rotateLR(parent);
		}
		// hDiff�� -1���� �۴ٸ� ������ ����Ʈ���� �ʹ� ����.
		else if (hDiff < -1) {
			// �׷� ������ ����Ʈ������ �ٽ� �����μ��� ����. 0���� �۴ٴ� ����
			// ������ ����Ʈ���� ������ ����Ʈ���� �� ũ�ٴ� ���. RRȸ��
			if (getHeightDiff(parent->getRight()) < 0)
				parent = rotateRR(parent);
			// ������ ����Ʈ���� ���� ����Ʈ���� �� ũ�ٴ� ���. LLȸ��
			else
				parent = rotateRL(parent);
		}
		// ���� ����� ��Ʈ ��ȯ
		return parent;
	}
	// AVL Ʈ���� ���� ����
	void insert(int data)
	{
		if (isEmpty()) root = new BinaryNode(data);
		else root = insertAVL(root, data);
	}
	// ���� ���� �ڵ�. ���� ���Ը� �Ѵٰ� �����ϰ�, �������� �뷱���� ��ƾ� �Ѵ�.
	BinaryNode* insertAVL(BinaryNode* parent, int data)
	{
		// ������ �����Ͱ� ��Ʈ���� �۴ٸ� ���� ����Ʈ���� ����
		if (data < parent->getData()) {
			// ���� ����Ʈ���� ������� ������. �ٽ� �ڽ����� ������ ��ȯ ȣ��
			if (parent->getLeft() != nullptr)
				parent->setLeft(insertAVL(parent->getLeft(), data));
			// ���� ����Ʈ���� ��������� �׳� �ٷ� ����.
			else
				parent->setLeft(new BinaryNode(data));
			// �뷱�� ���
			return reBalance(parent);
		}
		// ������ �����Ͱ� ��Ʈ���� ũ�ٸ� ������ ����Ʈ���� ����
		else if (data > parent->getData()) {
			// ������ ����Ʈ���� ������� ������. �ڽ����� ������ ��ȯ ȣ��
			if (parent->getRight() != nullptr)
				parent->setRight(insertAVL(parent->getRight(), data));
			// ������ ����Ʈ���� ��������� �׳� �ٷ� ����
			else
				parent->setRight(new BinaryNode(data));
			return reBalance(parent);
		}
		// ������ �����Ͱ� ��Ʈ�� ���ٴ� ����ε�. ����ó��
		else {
			printf("�ߺ��� Ű ����\n");
			return nullptr;
		}
	}
};