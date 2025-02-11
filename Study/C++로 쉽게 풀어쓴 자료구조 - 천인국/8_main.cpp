#include "BinaryTree.h"
#include "ThreadBinaryTree.h"

int main()
{
	//	tree
	//			A
	//		  /   \
	//		 B     C
	//	   /  \   /
	//	  D   E  F

	printf("   첫 번째 줄은 tree에서 구현, 두 번째 줄은 node에서 구현.");
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D', nullptr, nullptr);
	BinaryNode* e = new BinaryNode('E', nullptr, nullptr);
	BinaryNode* b = new BinaryNode('B', d, e);
	BinaryNode* f = new BinaryNode('F', nullptr, nullptr);
	BinaryNode* c = new BinaryNode('C', f, nullptr);
	BinaryNode* a = new BinaryNode('A', b, c);
	tree.setRoot(a);
	tree.inorder_t();
	tree.inorder_n();
	tree.preorder_t();
	tree.preorder_n();
	tree.postorder_t();
	tree.postorder_n();
	tree.levelorder();
	printf("   tree 노드의 개수: %d\n", tree.getCount_t());
	printf("   tree 노드의 개수: %d\n", tree.getCount_n());
	printf("   tree 리프의 개수: %d\n", tree.getLeafCount_t());
	printf("   tree 리프의 개수: %d\n", tree.getLeafCount_n());
	printf("   tree 높이: %d\n", tree.getHeight_t());
	printf("   tree 높이: %d\n", tree.getHeight_n());
	
	//	tree2
	//			+
	//		  /   \
	//		 *     -
	//	   /  \   /  \
	//	  3   2   5   6

	BinaryTree tree2;
	BinaryNode* n1 = new BinaryNode(3, nullptr, nullptr);
	BinaryNode* n2 = new BinaryNode(2, nullptr, nullptr);
	BinaryNode* n3 = new BinaryNode('*', n1, n2);
	BinaryNode* n4 = new BinaryNode(5, nullptr, nullptr);
	BinaryNode* n5 = new BinaryNode(6, nullptr, nullptr);
	BinaryNode* n6 = new BinaryNode('-', n4, n5);
	BinaryNode* n7 = new BinaryNode('+', n3, n6);
	tree2.setRoot(n7);
	printf("   tree2 계산 결과 = %d\n", tree2.evaluate());

	//	tree3
	//			0
	//		  /   \
	//		50    100
	//	          /  \
	//	        200  500
	
	BinaryTree tree3;
	BinaryNode* m4 = new BinaryNode(200, nullptr, nullptr);
	BinaryNode* m5 = new BinaryNode(500, nullptr, nullptr);
	BinaryNode* m3 = new BinaryNode(100, m4, m5);
	BinaryNode* m2 = new BinaryNode(50, nullptr, nullptr);
	BinaryNode* m1 = new BinaryNode(0, m2, m3);
	tree3.setRoot(m1);
	printf("   tree3 디렉터리 용량: %d KB\n", tree3.calcSize());

	//	tree4
	//			1
	//		  /   \
	//		 2     3
	//	   /  \     
	//	  4    5      
	//	 /
	//	6
	
	BinaryTree tree4;
	BinaryNode* a2 = new BinaryNode(5, nullptr, nullptr);
	BinaryNode* a3 = new BinaryNode(6, nullptr, nullptr);
	BinaryNode* a1 = new BinaryNode(4, a3, nullptr);
	BinaryNode* a4 = new BinaryNode(2, a1, a2);
	BinaryNode* a5 = new BinaryNode(3, nullptr, nullptr);
	BinaryNode* a6 = new BinaryNode(1, a4, a5);
	tree4.setRoot(a6);
	printf("   tree는 완전 이진 트리인가?(iterative): %d\n", tree.isComplete_Iter());
	printf("   tree는 완전 이진 트리인가?(recursive): %d\n", tree.isComplete_Recur());
	printf("   tree2는 완전 이진 트리인가?(iterative): %d\n", tree2.isComplete_Iter());
	printf("   tree2는 완전 이진 트리인가?(recursive): %d\n", tree2.isComplete_Recur());
	printf("   tree3는 완전 이진 트리인가?(iterative): %d\n", tree3.isComplete_Iter());
	printf("   tree3는 완전 이진 트리인가?(recursive): %d\n", tree3.isComplete_Recur());
	printf("   tree4는 완전 이진 트리인가?(iterative): %d\n", tree4.isComplete_Iter());
	printf("   tree4는 완전 이진 트리인가?(recursive): %d\n", tree4.isComplete_Recur());

	printf("   tree4의 3의 레벨(iterative): %d\n", tree4.getLevel_Iter(a5));
	printf("   tree4의 3의 레벨(recursive): %d\n", tree4.getLevel_Recur(a5));
	printf("   tree3의 200의 레벨(iterative): %d\n", tree3.getLevel_Iter(m4));
	printf("   tree3의 200의 레벨(recursive): %d\n", tree3.getLevel_Recur(m4));
	printf("   tree의 A의 레벨(iterative): %d\n", tree.getLevel_Iter(a));
	printf("   tree의 A의 레벨(recursive): %d\n", tree.getLevel_Recur(a));

	printf("   tree는 균형 잡혀 있는가?: %d\n", tree.isBalanced());
	printf("   tree2는 균형 잡혀 있는가?: %d\n", tree2.isBalanced());
	printf("   tree3은 균형 잡혀 있는가?: %d\n", tree3.isBalanced());
	printf("   tree4는 균형 잡혀 있는가?: %d\n", tree4.isBalanced());

	printf("   tree 경로의 길이: %d\n", tree.pathLength());
	printf("   tree2 경로의 길이: %d\n", tree2.pathLength());
	printf("   tree3 경로의 길이: %d\n", tree3.pathLength());
	printf("   tree4 경로의 길이: %d\n", tree4.pathLength());

	printf("   tree의 reverse(iterative): %d", tree.reverse_Iter());
	tree.levelorder();
	printf("   tree의 reverse(recursive): %d", tree.reverse_Recur());
	tree.levelorder();

	ThreadedBinTree ThreadTree;
	ThreadedBinNode* b1 = new ThreadedBinNode('A', nullptr, nullptr, true);
	ThreadedBinNode* b2 = new ThreadedBinNode('B', nullptr, nullptr, true);
	ThreadedBinNode* b3 = new ThreadedBinNode('C', b1, b2, false);
	ThreadedBinNode* b4 = new ThreadedBinNode('D', nullptr, nullptr, true);
	ThreadedBinNode* b5 = new ThreadedBinNode('E', nullptr, nullptr, false);
	ThreadedBinNode* b6 = new ThreadedBinNode('F', b4, b5, false);
	ThreadedBinNode* b7 = new ThreadedBinNode('G', b3, b6, false);
	ThreadTree.setRoot(b7);
	b1->setRight(b3);
	b2->setRight(b7);
	b4->setRight(b6);
	ThreadTree.threadedInorder();

	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;
	delete b6;
	delete b7;
	delete e;
	delete b;
	delete f;
	delete c;
	delete a;
	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete n6;
	delete n7;
	delete m4;
	delete m5;
	delete m3;
	delete m2;
	delete m1;
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	delete a6;
	
}