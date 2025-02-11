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

	printf("   ����� ���� = %d\n", tree.getCount_n());
	printf("   �ܸ��� ���� = %d\n", tree.getLeafCount_n());
	printf("   Ʈ���� ���� = %d\n", tree.getHeight_n());

	tree.inorder_n();
	tree.preorder_n();
	tree.postorder_n();
	tree.levelorder();

	tree.search_n(26);
	tree.search_n(25);

	printf("\n   case 1 ==> ��� 3 ����");
	tree.remove(3);
	tree.levelorder();
	printf("\n   case 2 ==> ��� 68 ����");
	tree.remove(68);
	tree.levelorder();
	printf("\n   case 3 ==> ��� 18 ����");
	tree.remove(18);
	tree.levelorder();
	printf("\n   case 3 ==> ��� 35 ���� (��Ʈ ��� ����)");
	tree.remove(35);
	tree.levelorder();

	printf("   ����� ���� = %d\n", tree.getCount_n());
	printf("   �ܸ��� ���� = %d\n", tree.getLeafCount_n());
	printf("   Ʈ���� ���� = %d\n", tree.getHeight_n());

	int a = 5;
}