#pragma once
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree() {}
	~BinSrchTree() {}

	// ȿ������ ������ �ݺ����� �Լ��� �ξ� ���
	BinaryNode* searchIter_t(int key)
	{
		BinaryNode* node = searchIter_t(root, key);
		if (node != nullptr)
			printf("   Ž�� ����: Ű ���� %d�� ��� = 0x%p\n", node->getData(), node);
		else
			printf("   Ž�� ����: Ű ���� %d�� ��� ����\n", key);
		return node;
	}
	BinaryNode* searchIter_t(BinaryNode* n, int key)
	{
		while (n != nullptr) {
			if (key == n->getData())
				return n;
			else if (key < n->getData())
				n = n->getLeft();
			else
				n = n->getRight();
		}
		return nullptr;
	}

	BinaryNode* searchRecur_t(int key) 
	{
		BinaryNode* node = searchRecur_t(root, key);
		if (node != nullptr)
			printf("   Ž�� ����: Ű ���� %d�� ��� = 0x%p\n", node->getData(), node);
		else
			printf("   Ž�� ����: Ű ���� %d�� ��� ����\n", key);
		return node;
	}
	BinaryNode* searchRecur_t(BinaryNode* n, int key)
	{
		if (n == nullptr)
			return nullptr;
		if (key == n->getData())
			return n;
		else if (key < n->getData())
			return searchRecur_t(n->getLeft(), key);
		else
			return searchRecur_t(n->getRight(), key);
	}
	BinaryNode* search_n(int key)
	{
		BinaryNode* node = root->search_n(key);
		if (node != nullptr)
			printf("   Ž�� ����: Ű ���� %d�� ��� = 0x%p\n", node->getData(), node);
		else
			printf("   Ž�� ����: Ű ���� %d�� ��� ����\n", key);
		return node;
	}

	void insertIter_t(BinaryNode* n) 
	{
		if (n == nullptr) return;
		if (isEmpty()) root = n;
		else insertIter_t(root, n);
	}
	void insertIter_t(BinaryNode* r, BinaryNode* n)
	{
		while (r != nullptr) {
			if (n->getData() == r->getData())
				return;
			else if (n->getData() < r->getData()) {
				if (r->getLeft() == nullptr) {
					r->setLeft(n);
					break;
				}
				else
					r = r->getLeft();
			}
			else {
				if (r->getRight() == nullptr) {
					r->setRight(n);
					break;
				}
				else
					r = r->getRight();
			}
		}
	}

	void insertRecur_t(BinaryNode* n)
	{
		if (n == nullptr) return;
		if (isEmpty()) root = n;
		else insertRecur_t(root, n);
	}
	void insertRecur_t(BinaryNode* r, BinaryNode* n)
	{
		if (n->getData() == r->getData())
			return;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == nullptr)
				r->setLeft(n);
			else
				insertRecur_t(r->getLeft(), n);
		}
		else {
			if (r->getRight() == nullptr)
				r->setRight(n);
			else
				insertRecur_t(r->getRight(), n);
		}
	}

	void insert_n(BinaryNode* node)
	{
		if (node == nullptr) return;
		if (root == nullptr) {
			root = node;
			return;
		}
		root->insert_n(node);
	}
	
	void remove(int key) 
	{
		if (isEmpty()) return;

		BinaryNode* parent = nullptr;
		BinaryNode* node = root;
		// �����ϱ����� ������ ��带 ã�´�.
		while (node != nullptr && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ?
				node->getLeft() : node->getRight();
		}
		// Ʈ���� ������ ��尡 ����
		if (node == nullptr) {
			printf("   Error: key is not in the tree!\n");
			return;
		}
		// ���⼭ parent�� ������ ����� �θ�
		// node�� ������ ���
		else
			remove(parent, node);
	}
	void remove(BinaryNode* parent, BinaryNode* node) 
	{
		// case 1: �����Ϸ��� ��尡 �ܸ�
		if (node->isLeaf()) {
			if (parent == nullptr)
				root = nullptr;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(nullptr);
				else
					parent->setRight(nullptr);
			}
		}
		// case 2: ����Ʈ���� �� �ʸ� �ִ� ���
		else if (node->getLeft() == nullptr || node->getRight() == nullptr) {
			BinaryNode* child = (node->getLeft() != nullptr) ?
				node->getLeft() : node->getRight();
			if (node == root) root = child;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		// case 3: ����Ʈ���� ���ʿ� �ִ� ���, ������ ����Ʈ���� �ּڰ��� �İ��ڷ� ��´�.
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();

			// ������ ����Ʈ���� �ּڰ��� �� ����� �θ�
			while (succ->getLeft() != nullptr) {
				succp = succ;
				succ = succ->getLeft();
			}

			// succp�� �İ��� ����� �θ��̰�, succ�� �İ��� ����̴�.
			// succp�� ���� �ڽ��� �İ��� ����̸�, succp�� ���� �ڽ��� null�� �����
			// ������ succ->getRight()�� nullptr�̴�.
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			// �� ���� succp�� �İ��� ����� �θ��ε�, �� �θ� ��尡 �ٷ� ������ ����̾�����,
			// ��, �İ��� ���� ������ ����� ������ �ڽ��� �� ������ �����ȴ�.
			// �׷��� ������ ����� ������ �ڽ��� null�� �����.
			else 
				succp->setRight(succ->getRight());

			// node�� ��ũ���� �ٲٴ� ���� �ƴ϶�, ������ ��� �ȿ� �����͸� �İ��� ����� �����ͷ� �ٲ۴�.
			// ���� ������ �����Ǵ� ���� �İ��� ����̰�, 
			// �����Ϸ��� �ߴ� ���� �İ��� ����� �����ͷ� ���������.
			node->setData(succ->getData());
			// node�� ������ ��带 ����Ű�� ��.��.�Ϳ���, �� �����Ͱ� ���� succ �İ��� ��带 ����Ų��.
			// ������ ������ ��� ���̴�.
			node = succ;
		}

		delete node;
	}
};