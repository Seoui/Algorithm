#pragma once
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

class BinaryNode
{
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
		: data(val), left(l), right(r) {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == nullptr && right == nullptr; }

	void preorder_n()
	{
		printf("[%d] ", data);
		if (left != nullptr) left->preorder_n();
		if (right != nullptr) right->preorder_n();
	}
	void inorder_n()
	{
		if (left != nullptr) left->inorder_n();
		printf("[%d] ", data);
		if (right != nullptr) right->inorder_n();
	}
	void postorder_n()
	{
		if (left != nullptr) left->postorder_n();
		if (right != nullptr) right->postorder_n();
		printf("[%d] ", data);
	}

	int getCount_n()
	{
		int cLeft = 0, cRight = 0;
		if (left != nullptr)
			cLeft = left->getCount_n();
		if (right != nullptr)
			cRight = right->getCount_n();
		return 1 + cLeft + cRight;
	}

	int getHeight_n()
	{
		int hLeft = 0, hRight = 0;
		if (left != nullptr)
			hLeft = left->getHeight_n();
		if (right != nullptr)
			hRight = right->getHeight_n();
		return hLeft > hRight ? hLeft + 1 : hRight + 1;
	}

	int getLeafCount_n()
	{
		int lLeft = 0, lRight = 0;
		if (isLeaf())
			return 1;
		if (left != nullptr)
			lLeft = left->getLeafCount_n();
		if (right != nullptr)
			lRight = right->getLeafCount_n();
		return lLeft + lRight;
	}

	BinaryNode* search_n(int key)
	{
		if (key == data)
			return this;
		else if (key < data && left != nullptr)
			return left->search_n(key);
		else if (key > data && right != nullptr)
			return right->search_n(key);
		else
			return nullptr;
	}

	void insert_n(BinaryNode* node)
	{
		if (node->getData() == data)
			return;
		else if (node->getData() < data) {
			if (left == nullptr)
				left = node;
			else
				left->insert_n(node);
		}
		else {
			if (right == nullptr)
				right = node;
			else
				right->insert_n(node);
		}
	}
};

class BinaryTree
{
protected:
	BinaryNode* root;

public:
	BinaryTree() : root(nullptr) {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == nullptr; }

	void preorder_t() { printf("\n   preorder_t: "); preorder_t(root); }
	void preorder_t(BinaryNode* node)
	{
		if (node == nullptr) return;
		printf("[%d] ", node->getData());
		preorder_t(node->getLeft());
		preorder_t(node->getRight());
	}

	void inorder_t() { printf("\n   inorder_t: "); inorder_t(root); }
	void inorder_t(BinaryNode* node)
	{
		if (node == nullptr) return;
		inorder_t(node->getLeft());
		printf("[%d] ", node->getData());
		inorder_t(node->getRight());
	}

	void postorder_t() { printf("\n   postorder_t: "); postorder_t(root); }
	void postorder_t(BinaryNode* node)
	{
		if (node == nullptr) return;
		postorder_t(node->getLeft());
		postorder_t(node->getRight());
		printf("[%d] ", node->getData());
	}

	void levelorder()
	{
		printf("\n   levelorder: ");
		if (!isEmpty()) {
			queue<BinaryNode*> q;
			q.push(root);
			while (!q.empty()) {
				BinaryNode* n = q.front();
				q.pop();
				if (n != nullptr) {
					printf("[%d] ", n->getData());
					q.push(n->getLeft());
					q.push(n->getRight());
				}
			}
		}
		printf("\n");
	}

	int getCount_t() { return isEmpty() ? 0 : getCount_t(root); }
	int getCount_t(BinaryNode* node)
	{
		if (node == nullptr)
			return 0;
		return 1 + getCount_t(node->getLeft()) + getCount_t(node->getRight());
	}

	int getHeight_t() { return isEmpty() ? 0 : getHeight_t(root); }
	int getHeight_t(BinaryNode* node)
	{
		if (node == nullptr)
			return 0;
		int hLeft = getHeight_t(node->getLeft());
		int hRight = getHeight_t(node->getRight());
		return hLeft > hRight ? hLeft + 1 : hRight + 1;
		// max 함수로 처리 가능
		// return 1 + max(getHeight(node->getLeft()), getHeight(node->getRight()));
	}

	int getLeafCount_t() { return isEmpty() ? 0 : getLeafCount_t(root); }
	int getLeafCount_t(BinaryNode* node)
	{
		if (node == nullptr)
			return 0;
		if (node->isLeaf())
			return 1;
		else
			return getLeafCount_t(node->getLeft()) + getLeafCount_t(node->getRight());
	}

	// 수식 트리 계산 알고리즘
	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		if (node->isLeaf()) return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
			}
			return 0;
		}
	}

	// 디렉터리 용량 계산 알고리즘
	int calcSize() { return calcSize(root); }
	int calcSize(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}

	bool isComplete_Iter()
	{
		if (root == nullptr) return true;
		return isComplete_Iter(root);
	}
	bool isComplete_Iter(BinaryNode* node)
	{
		queue<BinaryNode*> q;
		q.push(node);
		bool flag = false;

		while (!q.empty()) {
			BinaryNode* n = q.front();
			q.pop();
			if (n->getLeft()) {
				if (flag == true)
					return false;
				q.push(n->getLeft());
			}
			else
				flag = true;

			if (n->getRight()) {
				if (flag == true)
					return false;
				q.push(n->getRight());
			}
			else
				flag = true;
		}
		return true;
	}

	bool isComplete_Recur()
	{
		if (root == nullptr)
			return true;
		return isComplete_Recur(root, 0);
	}
	bool isComplete_Recur(BinaryNode* node, int index)
	{
		if (node == nullptr)
			return true;
		if (index >= getCount_n())
			return false;

		BinaryNode* leftNode = nullptr;
		BinaryNode* rightNode = nullptr;
		if (node != nullptr) {
			leftNode = node->getLeft();
			rightNode = node->getRight();
		}
		return isComplete_Recur(leftNode, 2 * index + 1) &&
			isComplete_Recur(rightNode, 2 * index + 2);
	}

	int getLevel_Iter(BinaryNode* node) { return getLevel_Iter(root, node); }
	int getLevel_Iter(BinaryNode* root, BinaryNode* node)
	{
		queue<BinaryNode*> q;
		int level = 1;
		q.push(root);
		q.push(nullptr);
		while (!q.empty()) {
			BinaryNode* tmp = q.front();
			q.pop();
			if (tmp == nullptr) {
				if (q.front() != nullptr)
					q.push(nullptr);
				level += 1;
			}
			else {
				if (tmp->getData() == node->getData())
					return level;
				if (tmp->getLeft())
					q.push(tmp->getLeft());
				if (tmp->getRight())
					q.push(tmp->getRight());
			}
		}

		return 0;
	}

	int getLevel_Recur(BinaryNode* node)
	{
		if (root == nullptr) return 0;
		return getLevel_Recur(root, node, 1);
	}
	int getLevel_Recur(BinaryNode* root, BinaryNode* node, int level)
	{
		if (root == nullptr) return 0;

		if (root->getData() == node->getData())
			return level;

		int downlevel = getLevel_Recur(root->getLeft(), node, level + 1);
		if (downlevel != 0)
			return downlevel;

		downlevel = getLevel_Recur(root->getRight(), node, level + 1);
		return downlevel;
	}

	bool isBalanced() { return isBalanced(root); }
	bool isBalanced(BinaryNode* node)
	{
		int lh = 0;
		int rh = 0;

		if (node == nullptr)
			return 1;

		if (node->getLeft() != nullptr)
			lh = node->getLeft()->getHeight_n();
		if (node->getRight() != nullptr)
			rh = node->getRight()->getHeight_n();

		if (abs(lh - rh) <= 1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))
			return 1;

		return 0;
	}

	int pathLength() { return pathLength(root); }
	int pathLength(BinaryNode* node)
	{
		int length = 0;
		if (!isEmpty()) {
			queue<BinaryNode*> q;
			q.push(node);
			while (!q.empty()) {
				BinaryNode* n = q.front();
				q.pop();
				if (n != nullptr) {
					length += getLevel_Iter(n) - 1;
					q.push(n->getLeft());
					q.push(n->getRight());
				}
			}
		}
		return length;
	}

	bool reverse_Iter() { return reverse_Iter(root); }
	bool reverse_Iter(BinaryNode* node)
	{
		if (node == nullptr)
			return false;

		queue<BinaryNode*> q;
		q.push(node);
		while (!q.empty()) {
			BinaryNode* n = q.front();
			q.pop();

			BinaryNode* tmp;
			tmp = n->getLeft();
			n->setLeft(n->getRight());
			n->setRight(tmp);

			if (n->getLeft())
				q.push(n->getLeft());
			if (n->getRight())
				q.push(n->getRight());
		}
		return true;
	}

	bool reverse_Recur() { return reverse_Recur(root); }
	bool reverse_Recur(BinaryNode* node)
	{
		if (node == nullptr)
			return false;
		else {
			BinaryNode* tmp;
			reverse_Recur(node->getLeft());
			reverse_Recur(node->getRight());

			tmp = node->getLeft();
			node->setLeft(node->getRight());
			node->setRight(tmp);
			return true;
		}
	}

	void inorder_n()
	{
		printf("\n   inorder_n: ");
		if (!isEmpty())
			root->inorder_n();
	}
	void preorder_n()
	{
		printf("\n   preorder_n: ");
		if (!isEmpty())
			root->preorder_n();
	}
	void postorder_n()
	{
		printf("\n   postorder_n: ");
		if (!isEmpty())
			root->postorder_n();
	}
	int getCount_n()
	{
		return isEmpty() ? 0 : root->getCount_n();
	}
	int getHeight_n()
	{
		return isEmpty() ? 0 : root->getHeight_n();
	}
	int getLeafCount_n()
	{
		return isEmpty() ? 0 : root->getLeafCount_n();
	}

	bool isDisjointFrom(BinaryTree* that);

	bool isValid();
};