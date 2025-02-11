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
		// 삭제하기전에 삭제할 노드를 찾는다.
		while (node != nullptr && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ?
				node->getLeft() : node->getRight();
		}
		// 트리에 삭제할 노드가 없음
		if (node == nullptr) {
			printf("   Error: key is not in the tree!\n");
			return;
		}
		// 여기서 parent는 삭제할 노드의 부모
		// node는 삭제할 노드
		else
			remove(parent, node);
	}
	void remove(BinaryNode* parent, BinaryNode* node) 
	{
		// case 1: 삭제하려는 노드가 단말
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
		// case 2: 서브트리가 한 쪽만 있는 경우
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
		// case 3: 서브트리가 양쪽에 있는 경우, 오른쪽 서브트리의 최솟값을 후계자로 삼는다.
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();

			// 오른쪽 서브트리의 최솟값과 그 노드의 부모
			while (succ->getLeft() != nullptr) {
				succp = succ;
				succ = succ->getLeft();
			}

			// succp는 후계자 노드의 부모이고, succ는 후계자 노드이다.
			// succp의 왼쪽 자식이 후계자 노드이면, succp의 왼쪽 자식을 null로 만든다
			// 어차피 succ->getRight()는 nullptr이다.
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			// 이 경우는 succp는 후계자 노드의 부모인데, 이 부모 노드가 바로 삭제할 노드이었을때,
			// 즉, 후계자 노드는 삭제할 노드의 오른쪽 자식일 때 조건이 만족된다.
			// 그러면 삭제할 노드의 오른쪽 자식을 null로 만든다.
			else 
				succp->setRight(succ->getRight());

			// node의 링크들을 바꾸는 것이 아니라, 삭제할 노드 안에 데이터를 후계자 노드의 데이터로 바꾼다.
			// 따라서 실제로 삭제되는 노드는 후계자 노드이고, 
			// 삭제하려고 했던 노드는 후계자 노드의 데이터로 덮어씌워졌다.
			node->setData(succ->getData());
			// node는 삭제될 노드를 가리키던 포.인.터였고, 이 포인터가 이제 succ 후계자 노드를 가리킨다.
			// 실제로 삭제할 노드 말이다.
			node = succ;
		}

		delete node;
	}
};