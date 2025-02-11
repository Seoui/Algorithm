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

	// 노드 클래스에서의 순환적인 탐색 함수
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
	// 노드 클래스에서의 insert 함수
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

	// 완전 이진 트리인지 검사하는 알고리즘
	bool isComplete_Iter()
	{
		// 빈 트리라면 완전 이진 트리이다.
		if (root == nullptr) return true;
		return isComplete_Iter(root);
	}
	bool isComplete_Iter(BinaryNode* node)
	{
		queue<BinaryNode*> q;
		q.push(node);
		// flag는 현재 노드가 full node인지 아닌지에 대한 여부이다.
		// flag == false이면 full node이다.
		// flag == true이면 full node가 아니다.
		bool flag = false;

		while (!q.empty()) {
			BinaryNode* n = q.front();
			q.pop();
			if (n->getLeft()) {
				/* 아래 if문에 걸릴 조건은
				   앞서 우리가 봤던 노드들 중 full node가 아닌
				   노드가 있었다는 의미다.
				   자식이 어디 하나 없는 node가 있었다는 것이고.
				   현재 노드의 왼쪽 자식은 있는데, 앞서 봤던 노드의 자식이 없다는 것은
				   완전 이진 트리가 될 수 없다는 뜻! */
				if (flag == true)
					return false;
				q.push(n->getLeft());
			}
			// 현재 노드의 왼쪽 자식이 없다면, full node가 아니다.
			else
				flag = true;

			if (n->getRight()) {
				/* 아래 if문에 걸릴 조건은 위와 같지만 추가적으로,
				   위 if문에서 즉, 현재 노드의 왼쪽 자식이 없어서
				   flat == ture가 됬는데 현재 노드의 오른쪽 자식이 있어서 여기 if문으로
				   진입했고 아래 if문의 조건을 만족하기 한다.
				   이것은 완전 이진 트리가 될 수 없다. */
				if (flag == true)
					return false;
				q.push(n->getRight());
			}
			// 현재 노드의 오른쪽 자식이 없다면, full node가 아니다.
			else
				flag = true;
		}
		
		/* 정리하자면 flag 변수는 레벨 순회를 하다가
		   full node가 아닌 노드를 만나면 flag를 true로 설정한다.
		   이 뜻은 처음으로 full node가 아닌 노드가 나오면 이 이후의 노드들은
		   모두 자식을 가지면 안된다는 뜻이다. */
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
		/* 만약 index가 노드의 개수보다 크거나 같아진다면,
		   이 노드는 완전 이진 트리가 아니다.
		   당연하게도 노드의 index는 노드의 개수보다 크거나 같을 수 없다. */
		if (index >= getCount_n())
			return false;

		/*
		BinaryNode* leftNode = nullptr;
		BinaryNode* rightNode = nullptr;
		if (node != nullptr) {
			leftNode = node->getLeft();
			rightNode = node->getRight();
		}*/

		/* 모든 노드의 인덱스를 넘기면서 노드의 개수와 계속 비교한다.
		   false를 반환하는 경우는 오직 index가 노드의 개수보다 크거나 같아졌을 때이다.
		   다시 한번 상기할 것은 노드의 개수는 항상 최대 인덱스보다 커야만 완전 이진 트리가 될 수고 있고,
		   만약 노드의 개수가 최대 인덱스보다 작거나 같다면 완전 이진 트리가 될 수 없다.
		   인덱스가 노드의 개수보다 크거가 같아진다는 의미는
		   중간에 어떤 노드를 건너뛰었다는 의미다.(앞에 빈 공간이 있다는 것) */
		return isComplete_Recur(node->getLeft(), 2 * index + 1) &&
			isComplete_Recur(node->getRight(), 2 * index + 2);
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
				if (q.front() != nullptr) // 이 조건은 왜 있는 걸까.?
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
		while (!q.empty())
		{
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