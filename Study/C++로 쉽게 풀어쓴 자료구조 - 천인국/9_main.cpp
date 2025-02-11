#include "BinarySearchTree.h"

int main()
{
	BinSrchTree tree;

	tree.insert_n(new BinaryNode(35));
	tree.insert_n(new BinaryNode(18));
	tree.insert_n(new BinaryNode(7));
	tree.insert_n(new BinaryNode(26));
	tree.insert_n(new BinaryNode(12));
	tree.insert_n(new BinaryNode(3));
	tree.insert_n(new BinaryNode(68));
	tree.insert_n(new BinaryNode(22));
	tree.insert_n(new BinaryNode(30));
	tree.insert_n(new BinaryNode(99));

	printf("   노드의 개수 = %d\n", tree.getCount_n());
	printf("   단말의 개수 = %d\n", tree.getLeafCount_n());
	printf("   트리의 높이 = %d\n", tree.getHeight_n());

	tree.inorder_n();
	tree.preorder_n();
	tree.postorder_n();
	tree.levelorder();

	tree.search_n(26);
	tree.search_n(25);

	printf("\n   case 1 ==> 노드 3 삭제");
	tree.remove(3);
	tree.levelorder();
	printf("\n   case 2 ==> 노드 68 삭제");
	tree.remove(68);
	tree.levelorder();
	printf("\n   case 3 ==> 노드 18 삭제");
	tree.remove(18);
	tree.levelorder();
	printf("\n   case 3 ==> 노드 35 삭제 (루트 노드 삭제)");
	tree.remove(35);
	tree.levelorder();

	printf("   노드의 개수 = %d\n", tree.getCount_n());
	printf("   단말의 개수 = %d\n", tree.getLeafCount_n());
	printf("   트리의 높이 = %d\n", tree.getHeight_n());

	int a = 5;
}