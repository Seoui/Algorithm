#include <iostream>
#include <cstdio>
#include "AVLTree.h"
#include "HashMap.h"
#include <map>
using namespace std;

// ���ĵ��� ���� �迭������ ���� Ž��
int sequentialSearch(int list[], int key, int low, int high)
{
	// ��ü �迭�� ��ȸ�ϸ鼭 key�� ��ġ�� �ε����� ã�� ��ȯ
	for (int i = low; i <= high; ++i)
		if (list[i] == key)
			return i;
	// ��ã���� -1
	return -1;
}

// ���ĵ� �迭������ ���� Ž��
int sortedSequentialSearch(int list[], int key, int low, int high)
{
	// ���� ��ü �迭�� ��ȸ�ϸ鼭 key�� ��ġ�� �ε����� ã�� ��ȯ�Ѵ�.
	// ���ĵ��� ���� �迭������ ���� Ž���� �ٸ� ���� 
	// ã�� key���� �� ū ���� ã�ԵǸ� �ٷ� ������ �� �ִٴ� ��.(ã�� ���� ���� ��쿡 �̵��� ��)
	int i;
	for (i = low; i <= high; ++i){
		if (list[i] > key) return -1;
		if (list[i] == key) return i;
	}
	return -1;
}

// ���ĵ� �迭������ ���� Ž�� (��ȯ)
// ���� Ž���� �⺻������ Ž���� �ڷᰡ ���ĵǾ� �־�� ��
int binarySearch(int list[], int key, int low, int high)
{
	int middle;
	// low == high�� ���� ����� �и��� �迭�� 1���� ����.
	// �� ���� key�� ���� �� Ȯ���ؾ� ��.
	if (low <= high) {
		// middle�� Ȧ������ ���� ��Ȯ�� �߰� �ε�����
		// middle�� ¦������ ���� �߾��� �տ��ִ� ����(�� ���� ��)
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])
			return binarySearch(list, key, low, middle - 1);
		else
			return binarySearch(list, key, middle + 1, high);
	}
	return -1;
}

// ���ĵ� �迭������ ���� Ž�� (�ݺ�).
// �� ȿ����
int binarySearchIter(int list[], int key, int low, int high)
{
	int middle;
	while (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
}

// ���� ���� Ž������ ����� �ε��� ���̺� �׸��� ����ü
struct Index
{
	int key;	// Ű ��
	int index;	// Ű ���� �ε���
};

/*	
*	���� ���� Ž��(Indexed sequential search)
*	Ž���� �迭�� �ε��� ���̺� ��� ���ĵǾ� �־��� ��
*	nList:	�˻��� ������ ����Ʈ
*	tbl:	�ε��� ���̺�
*	nTbl:	�ε��� ���̺� ũ��
*	key:	ã�� �� 
*/
int indexedSearch(int list[], int nList, Index* tbl, int nTbl, int key)
{
	// Ű ���� ����Ʈ ���� ���̸� ��ٷ� ����
	if (key<list[0] || key>list[nList - 1])
		return -1;
	// �ε��� ���̺� ����
	for (int i = 0; i < nTbl - 1; ++i) {
		// ���� ã�� key�� �ε��� ���̺��� �� ���һ��̿� �ִٸ�(���� �Ͱ� ���Ƶ� ��)
		if (tbl[i].key <= key && tbl[i + 1].key > key)
			// �� �ȿ��� ���� Ž���Ѵ�
			return sequentialSearch(list, key, tbl[i].index, tbl[i + 1].index);
	}
	// for���� ������ �ε��� ���̺� �� ������ ����.
	// �ε��� ���̺��� ���̸�, Ž�� ������ ���� �ε������� �迭�� ��(nList)������ ��. �� ������ ���ؼ��� Ž�� ����
	return sequentialSearch(list, key, tbl[nTbl - 1].index, nList);
}

// ���� Ž��
int interpolationSearch(int list[], int nList, int key)
{
	int low = 0;
	int high = nList - 1;
	// ����Ʈ�� ���� ���� key���� �۰�, ����Ʈ�� ������ ���� key���� ũ�ų� ���ٸ� while�� ����.
	// ���� key�� (list[low], list[high]] ������ ����� while�� ������
	while ((list[low] < key) && (key <= list[high])) {
		// ������ �̿���. ��ü ���� �Ÿ� : key������ �Ÿ� = ��ü �ε����� �Ÿ� : key �ε��������� �Ÿ�
		// �Ǽ��� ������ ������ ĳ�����Ͽ� �Ҽ��� ���� ������.
		int j = int(float(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
		// ���� key�� ���� �ε����� ������ ũ�ٸ� ���� ���� �ε������� �ϳ� �� ū ���� ���ӿ� ���� ������ ������.
		// ���� while�������� ���� �����κ��� �� ������ �������� �ε��� �ٽ� ���
		if (key > list[j]) low = j + 1;
		// ���� ����
		else if (key < list[j]) high = j - 1;
		// ��Ȯ�ϰ� ã���� ����
		else return j;
	}

	return -1;
}

int main()
{
	printf("=============================================\n");
	printf("���ĵ��� ���� �迭������ ���� Ž��\n");
	int list1[8] = { 7, 8, 5, 11, 100, 0, 2, 9 };
	printf("�迭: ");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", list1[i]);
	}
	printf("\n");
	printf("���� Ž�� [2] ���: %d�� �ε����� ��ġ��\n", sequentialSearch(list1, 2, 0, 7));
	printf("���� Ž�� [10] ���: %d�� �ε����� ��ġ��\n", sequentialSearch(list1, 10, 0, 7));

	printf("=============================================\n");
	printf("���ĵ� �迭������ ���� Ž��\n");
	int list2[8] = { 0, 2, 5, 7, 8, 9, 11, 100 };
	printf("�迭: ");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", list2[i]);
	}
	printf("\n");
	printf("���� Ž�� [2] ���: %d�� �ε����� ��ġ��\n", sortedSequentialSearch(list2, 2, 0, 7));
	printf("���� Ž�� [10] ���: %d�� �ε����� ��ġ��\n", sortedSequentialSearch(list2, 10, 0, 7));

	printf("=============================================\n");
	printf("���� Ž��\n");
	int list3[8] = { 0, 2, 5, 7, 8, 9, 11, 100 };
	printf("�迭: ");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", list3[i]);
	}
	printf("\n");
	printf("���� Ž��(���) [2] ���: %d�� �ε����� ��ġ��\n", binarySearch(list3, 2, 0, 7));
	printf("���� Ž��(���) [10] ���: %d�� �ε����� ��ġ��\n", binarySearch(list3, 10, 0, 7));
	printf("���� Ž��(�ݺ�) [2] ���: %d�� �ε����� ��ġ��\n", binarySearchIter(list3, 2, 0, 7));
	printf("���� Ž��(�ݺ�) [10] ���: %d�� �ε����� ��ġ��\n", binarySearchIter(list3, 10, 0, 7));

	printf("=============================================\n");
	printf("���� ���� Ž��\n");
	const int LIST_SIZE = 9;
	const int INDEX_SIZE = 3;
	int list[LIST_SIZE] = { 3, 9, 15, 22, 31, 55, 67, 88, 91 };
	printf("�迭: ");
	for (int i = 0; i < 9; ++i) {
		printf("%d ", list[i]);
	}
	printf("\n");
	Index index[INDEX_SIZE] = { {3,0}, {15, 3}, {67, 6} };

	printf("Ž���� ����: 55\n");
	int ret = indexedSearch(list, LIST_SIZE, index, INDEX_SIZE, 55);
	if (ret >= 0) printf("Ž�� ����: ����(%d) ��ġ=%d\n", 55, ret);
	else printf("����(%d) Ž�� ����\n", 55);
	printf("Ž���� ����: 50\n");
	ret = indexedSearch(list, LIST_SIZE, index, INDEX_SIZE, 50);
	if (ret >= 0) printf("Ž�� ����: ����(%d) ��ġ=%d\n", 50, ret);
	else printf("Ž�� ����: ����(%d)\n", 50);


	printf("=============================================\n");
	printf("����Ž��\n");
	int list4[10] = { 3, 9, 15, 22, 31, 55, 67, 88, 89, 91 };
	printf("�迭: ");
	for (int i = 0; i < 10; ++i) {
		printf("%d ", list4[i]);
	}
	printf("\n");
	printf("���� Ž�� [55] ���: %d�� �ε����� ��ġ��\n", interpolationSearch(list4, 10, 55));
	printf("���� Ž�� [50] ���: %d�� �ε����� ��ġ��\n", interpolationSearch(list4, 10, 50));
	printf("=============================================\n");
	printf("AVL Tree\n");
	AVLTree tree;
	tree.insert(7);
	tree.levelorder();
	tree.insert(8);
	tree.levelorder();
	tree.insert(9);
	tree.levelorder();
	tree.insert(2);
	tree.levelorder();
	tree.insert(1);
	tree.levelorder();
	tree.insert(5);
	tree.levelorder();
	tree.insert(3);
	tree.levelorder();
	tree.insert(6);
	tree.levelorder();
	tree.insert(4);
	tree.levelorder();

	printf("=============================================\n");
	printf("�ؽ� ��\n");
	HashMap hash;
	hash.addLinearProb("do", "Interation");
	hash.addLinearProb("for", "Interation");
	hash.addLinearProb("if", "Branch");
	hash.addLinearProb("case", "Branch");
	hash.addLinearProb("else", "Branch");
	hash.addLinearProb("return", "Return");
	hash.addLinearProb("function", "Function");
	hash.display();
	hash.searchLinearProb("return");
	hash.searchLinearProb("class");
	hash.searchLinearProb("function");

	printf("=============================================\n");
	printf("�ؽ� ü�� ��\n");
	HashChainMap hashChain;
	hashChain.addRecord(new Node("do", "Interation"));
	hashChain.addRecord(new Node("for", "Interation"));
	hashChain.addRecord(new Node("if", "Branch"));
	hashChain.addRecord(new Node("case", "Branch"));
	hashChain.addRecord(new Node("else", "Branch"));
	hashChain.addRecord(new Node("return", "Return"));
	hashChain.addRecord(new Node("function", "Function"));
	hashChain.display();
	hashChain.searchRecord("return");
	hashChain.searchRecord("class");
	hashChain.searchRecord("function");

	printf("=============================================\n");
	printf("STL map\n");
	map<string, string> myDic;
	map<string, string>::iterator dp;
	myDic["hello"] = "�ȳ��ϼ���?";
	myDic["world"] = "�Ƹ��ٿ� ����";
	myDic["data"] = "������";
	myDic["structure"] = "����, ����ü";
	myDic["list"] = "����Ʈ";
	myDic["Pain past is pleasure"] = "������ ������ ��ſ��̴�";
	myDic["Habit is second nature"] = "������ ��2�� õ���̴�";
	myDic["No pain no gain"] = "���� ���̴� ��� �͵� ����";
	for (dp = begin(myDic); dp != end(myDic); ++dp)
		printf("%20s = %s\n", dp->first.c_str(), dp->second.c_str());

	dp = myDic.find("structure");
	if (dp == end(myDic))
		printf(" �˻� ����: ã�� �ܾ �����ϴ�\n");
	else
		printf(" �˻� ����: %s ---> %s\n", dp->first.c_str(), dp->second.c_str());

	dp = myDic.find("algorithm");
	if (dp == end(myDic))
		printf(" �˻� ����: ã�� �ܾ �����ϴ�\n");
	
	myDic.erase("list");
	dp = myDic.find("structure");
	myDic.erase(dp);

	for (dp = begin(myDic); dp != end(myDic); ++dp)
		printf("%20s = %s\n", dp->first.c_str(), dp->second.c_str());

}