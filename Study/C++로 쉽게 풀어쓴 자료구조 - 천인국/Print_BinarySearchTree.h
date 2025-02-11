#pragma once
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree() {}
	~BinSrchTree() {}

	// 효율성만 따지만 반복적인 함수가 훨씬 우수
	BinaryNode* searchIter_t(int key)
	{
		BinaryNode* node = searchIter_t(root, key);
		if (node != nullptr)
			printf("   탐색 성공: 키 값이 %d인 노드 = 0x%p\n", node->getData(), node);
		else
			printf("   탐색 실패: 키 값이 %d인 노드 없음\n", key);
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
			printf("   탐색 성공: 키 값이 %d인 노드 = 0x%p\n", node->getData(), node);
		else
			printf("   탐색 실패: 키 값이 %d인 노드 없음\n", key);
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
			printf("   탐색 성공: 키 값이 %d인 노드 = 0x%p\n", node->getData(), node);
		else
			printf("   탐색 실패: 키 값이 %d인 노드 없음\n", key);
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
		while (node != nullptr && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ?
				node->getLeft() : node->getRight();
		}
	
		if (node == nullptr) {
			printf("   Error: key is not in the tree!\n");
			return;
		}
		else
			remove(parent, node);
	}
	void remove(BinaryNode* parent, BinaryNode* node)
	{
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
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != nullptr) {
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());
			node = succ;
		}
		delete node;
	}
};