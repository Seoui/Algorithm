#pragma once
#include "BinarySearchTree.h"

class AVLTree : public BinSrchTree
{
public:
	int getHeightDiff(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		int hLeft = getHeight_t(node->getLeft());
		int hRight = getHeight_t(node->getRight());
		return hLeft - hRight;
	}

	BinaryNode* rotateLL(BinaryNode* parent)
	{
		BinaryNode* child = parent->getLeft();
		parent->setLeft(child->getRight());
		child->setRight(parent);
		return child;
	}

	BinaryNode* rotateRR(BinaryNode* parent)
	{
		BinaryNode* child = parent->getRight();
		parent->setRight(child->getLeft());
		child->setLeft(parent);
		return child;
	}

	BinaryNode* rotateRL(BinaryNode* parent)
	{
		BinaryNode* child = parent->getRight();
		parent->setRight(rotateLL(child));
		return rotateRR(parent);
	}

	BinaryNode* rotateLR(BinaryNode* parent)
	{
		BinaryNode* child = parent->getLeft();
		parent->setLeft(rotateRR(child));
		return rotateLL(parent);
	}

	BinaryNode* reBalance(BinaryNode* parent)
	{
		int hDiff = getHeightDiff(parent);
		if (hDiff > 1) {
			if (getHeightDiff(parent->getLeft()) > 0)
				parent = rotateLL(parent);
			else
				parent = rotateLR(parent);
		}
		else if (hDiff < -1) {
			if (getHeightDiff(parent->getRight()) < 0)
				parent = rotateRR(parent);
			else
				parent = rotateRL(parent);
		}
		return parent;
	}

	void insert(int data)
	{
		if (isEmpty()) root = new BinaryNode(data);
		else root = insertAVL(root, data);
	}

	BinaryNode* insertAVL(BinaryNode* parent, int data)
	{
		if (data < parent->getData()) {
			if (parent->getLeft() != nullptr)
				parent->setLeft(insertAVL(parent->getLeft(), data));
			else
				parent->setLeft(new BinaryNode(data));
			return reBalance(parent);
		}
		else if (data > parent->getData()) {
			if (parent->getRight() != nullptr)
				parent->setRight(insertAVL(parent->getRight(), data));
			else
				parent->setRight(new BinaryNode(data));
			return reBalance(parent);
		}
		else {
			printf("중복된 키 에러\n");
			return nullptr;
		}
	}
};
