#pragma once
#include "BinarySearchTree.h"

// AVL 트리는 이진 탐색 트리의 한 종류이다.
// 이진 탐색 트리의 모든 성질을 만족한다.
class AVLTree : public BinSrchTree
{
public:
	// 노드의 균형인수를 반환
	// 균형인수: (왼쪽 자식의 높이 - 오른쪽 자식의 높이)
	int getHeightDiff(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		int hLeft = getHeight_t(node->getLeft());
		int hRight = getHeight_t(node->getRight());
		return hLeft - hRight;
	}

	// LL회전(오른쪽에서 왼쪽으로 회전한다고 생각. 시계방향임)
	BinaryNode* rotateLL(BinaryNode* parent)
	{
		// 왼쪽 자식이 루트로 올라와야 하므로
		BinaryNode* child = parent->getLeft();
		// 루트의 왼쪽 자식은 원래의 왼쪽 자식의 오른쪽 자식이 됨.
		parent->setLeft(child->getRight());
		// 왼쪽 자식의 오른쪽 자식은 기존 루트로 갱신
		child->setRight(parent);
		// 새롭게 갱신된 루트 반환
		return child;
	}

	// RR회전(왼쪽에서 오른쪽으로 회전한다고 생각. 반시계방향임)
	BinaryNode* rotateRR(BinaryNode* parent)
	{
		// 오른쪽 자식이 루트로 올라와야 하므로
		BinaryNode* child = parent->getRight();
		// 루트의 오른쪽 자식은 원래의 오른쪽 자식의 왼쪽 자식이 됨.
		parent->setRight(child->getLeft());
		// 오른쪽 자식의 왼쪽 자식은 기존 루트로 갱신
		child->setLeft(parent);
		// 새롭게 갱신된 루트 반환
		return child;
	}
	// RL회전(LL회전 후 RR회전)
	BinaryNode* rotateRL(BinaryNode* parent)
	{
		// 처음 LL회전은 오른쪽 자식을 루트로 삼고 LL회전 한다.
		BinaryNode* child = parent->getRight();
		parent->setRight(rotateLL(child));
		// 그 다음 루트로 RR회전
		return rotateRR(parent);
	}
	// LR회전(RR회전 후 LL회전)
	BinaryNode* rotateLR(BinaryNode* parent)
	{
		// 처음 RR회전은 왼쪽 자식을 루트로 삼고 RR회전 한다.
		BinaryNode* child = parent->getLeft();
		parent->setLeft(rotateRR(child));
		// 그 다음 루트로 LL회전
		return rotateLL(parent);
	}
	// 트리를 균형트리로 만든다
	BinaryNode* reBalance(BinaryNode* parent)
	{
		int hDiff = getHeightDiff(parent);
		// hDiff가 1보다 크다면 왼쪽 서브트리가 너무 높다는 얘기
		if (hDiff > 1) {
			// 그럼 왼쪽 서브트리에서 다시 균형인수를 구해서 0보다 크다는 것은
			// 왼쪽 서브트리의 왼쪽 서브트리가 더 크다는 얘기. LL회전
			if (getHeightDiff(parent->getLeft()) > 0)
				parent = rotateLL(parent);
			// 왼쪽 서브트리의 오른쪽 서브트리가 더 크다. RR회전
			else
				parent = rotateLR(parent);
		}
		// hDiff가 -1보다 작다면 오른쪽 서브트리가 너무 높다.
		else if (hDiff < -1) {
			// 그럼 오른쪽 서브트리에서 다시 균형인수를 구함. 0보다 작다는 것은
			// 오른쪽 서브트리의 오른쪽 서브트리가 더 크다는 얘기. RR회전
			if (getHeightDiff(parent->getRight()) < 0)
				parent = rotateRR(parent);
			// 오른쪽 서브트리의 왼쪽 서브트리가 더 크다는 얘기. LL회전
			else
				parent = rotateRL(parent);
		}
		// 최종 결과의 루트 반환
		return parent;
	}
	// AVL 트리의 삽입 연산
	void insert(int data)
	{
		if (isEmpty()) root = new BinaryNode(data);
		else root = insertAVL(root, data);
	}
	// 실제 삽입 코드. 실제 삽입만 한다고 생각하고, 마지막에 밸런스를 잡아야 한다.
	BinaryNode* insertAVL(BinaryNode* parent, int data)
	{
		// 삽입할 데이터가 루트보다 작다면 왼쪽 서브트리에 삽입
		if (data < parent->getData()) {
			// 왼쪽 서브트리가 비어있지 않으면. 다시 자식으로 내려가 순환 호출
			if (parent->getLeft() != nullptr)
				parent->setLeft(insertAVL(parent->getLeft(), data));
			// 왼쪽 서브트리가 비어있으면 그냥 바로 삽입.
			else
				parent->setLeft(new BinaryNode(data));
			// 밸런스 잡기
			return reBalance(parent);
		}
		// 삽입할 데이터가 루트보다 크다면 오른쪽 서브트리에 삽입
		else if (data > parent->getData()) {
			// 오른쪽 서브트리가 비어있지 않으면. 자식으로 내려가 순환 호출
			if (parent->getRight() != nullptr)
				parent->setRight(insertAVL(parent->getRight(), data));
			// 오른쪽 서브트리가 비어있으면 그냥 바로 삽입
			else
				parent->setRight(new BinaryNode(data));
			return reBalance(parent);
		}
		// 삽입할 데이터가 루트와 같다는 얘기인데. 예외처리
		else {
			printf("중복된 키 에러\n");
			return nullptr;
		}
	}
};