#include <iostream>
#include <cstdio>
#include "AVLTree.h"
#include "HashMap.h"
#include <map>
using namespace std;

int sequentialSearch(int list[], int key, int low, int high)
{
	for (int i = low; i <= high; ++i)
		if (list[i] == key)
			return i;
	return -1;
}

int sortedSequentialSearch(int list[], int key, int low, int high)
{
	int i;
	for (i = low; i <= high; ++i) {
		if (list[i] > key) return -1;
		if (list[i] == key) return i;
	}
	return -1;
}

int binarySearch(int list[], int key, int low, int high)
{
	int middle;

	if (low <= high) {
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

struct Index
{
	int key;
	int index;
};

int indexedSearch(int list[], int nList, Index* tbl, int nTbl, int key)
{
	if (key<list[0] || key>list[nList - 1])
		return -1;
	for (int i = 0; i < nTbl - 1; ++i) {
		if (tbl[i].key <= key && tbl[i + 1].key > key)
			return sequentialSearch(list, key, tbl[i].index, tbl[i + 1].index);
	}
	return sequentialSearch(list, key, tbl[nTbl - 1].index, nList);
}

int interpolationSearch(int list[], int nList, int key)
{
	int low = 0;
	int high = nList - 1;
	while ((list[low] < key) && (key <= list[high])) {
		int j = int(float(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else return j;
	}

	return -1;
}

int main()
{
	printf("=============================================\n");
	printf("정렬되지 않은 배열에서의 순차 탐색\n");
	int list1[8] = { 7, 8, 5, 11, 100, 0, 2, 9 };
	printf("배열: ");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", list1[i]);
	}
	printf("\n");
	printf("순차 탐색 [2] 결과: %d번 인덱스에 위치함\n", sequentialSearch(list1, 2, 0, 7));
	printf("순차 탐색 [10] 결과: %d번 인덱스에 위치함\n", sequentialSearch(list1, 10, 0, 7));

	printf("=============================================\n");
	printf("정렬된 배열에서의 순차 탐색\n");
	int list2[8] = { 0, 2, 5, 7, 8, 9, 11, 100 };
	printf("배열: ");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", list2[i]);
	}
	printf("\n");
	printf("순차 탐색 [2] 결과: %d번 인덱스에 위치함\n", sortedSequentialSearch(list2, 2, 0, 7));
	printf("순차 탐색 [10] 결과: %d번 인덱스에 위치함\n", sortedSequentialSearch(list2, 10, 0, 7));

	printf("=============================================\n");
	printf("이진 탐색\n");
	int list3[8] = { 0, 2, 5, 7, 8, 9, 11, 100 };
	printf("배열: ");
	for (int i = 0; i < 8; ++i) {
		printf("%d ", list3[i]);
	}
	printf("\n");
	printf("이진 탐색(재귀) [2] 결과: %d번 인덱스에 위치함\n", binarySearch(list3, 2, 0, 7));
	printf("이진 탐색(재귀) [10] 결과: %d번 인덱스에 위치함\n", binarySearch(list3, 10, 0, 7));
	printf("이진 탐색(반복) [2] 결과: %d번 인덱스에 위치함\n", binarySearchIter(list3, 2, 0, 7));
	printf("이진 탐색(반복) [10] 결과: %d번 인덱스에 위치함\n", binarySearchIter(list3, 10, 0, 7));

	printf("=============================================\n");
	printf("색인 순차 탐색\n");
	const int LIST_SIZE = 9;
	const int INDEX_SIZE = 3;
	int list[LIST_SIZE] = { 3, 9, 15, 22, 31, 55, 67, 88, 91 };
	printf("배열: ");
	for (int i = 0; i < 9; ++i) {
		printf("%d ", list[i]);
	}
	printf("\n");
	Index index[INDEX_SIZE] = { {3,0}, {15, 3}, {67, 6} };

	printf("탐색할 숫자: 55\n");
	int ret = indexedSearch(list, LIST_SIZE, index, INDEX_SIZE, 55);
	if (ret >= 0) printf("탐색 성공: 숫자(%d) 위치=%d\n", 55, ret);
	else printf("숫자(%d) 탐색 실패\n", 55);
	printf("탐색할 숫자: 50\n");
	ret = indexedSearch(list, LIST_SIZE, index, INDEX_SIZE, 50);
	if (ret >= 0) printf("탐색 성공: 숫자(%d) 위치=%d\n", 50, ret);
	else printf("탐색 실패: 숫자(%d)\n", 50);


	printf("=============================================\n");
	printf("보간탐색\n");
	int list4[10] = { 3, 9, 15, 22, 31, 55, 67, 88, 89, 91 };
	printf("배열: ");
	for (int i = 0; i < 10; ++i) {
		printf("%d ", list4[i]);
	}
	printf("\n");
	printf("보간 탐색 [55] 결과: %d번 인덱스에 위치함\n", interpolationSearch(list4, 10, 55));
	printf("보간 탐색 [50] 결과: %d번 인덱스에 위치함\n", interpolationSearch(list4, 10, 50));
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
	printf("해쉬 맵\n");
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
	printf("해쉬 체인 맵\n");
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
	myDic["hello"] = "안녕하세요?";
	myDic["world"] = "아름다운 세상";
	myDic["data"] = "데이터";
	myDic["structure"] = "구조, 구조체";
	myDic["list"] = "리스트";
	myDic["Pain past is pleasure"] = "지나간 고통은 즐거움이다";
	myDic["Habit is second nature"] = "습관은 제2의 천성이다";
	myDic["No pain no gain"] = "고통 없이는 얻는 것도 없다";
	for (dp = begin(myDic); dp != end(myDic); ++dp)
		printf("%20s = %s\n", dp->first.c_str(), dp->second.c_str());

	dp = myDic.find("structure");
	if (dp == end(myDic))
		printf(" 검색 실패: 찾는 단어가 없습니다\n");
	else
		printf(" 검색 성공: %s ---> %s\n", dp->first.c_str(), dp->second.c_str());

	dp = myDic.find("algorithm");
	if (dp == end(myDic))
		printf(" 검색 실패: 찾는 단어가 없습니다\n");

	myDic.erase("list");
	dp = myDic.find("structure");
	myDic.erase(dp);

	for (dp = begin(myDic); dp != end(myDic); ++dp)
		printf("%20s = %s\n", dp->first.c_str(), dp->second.c_str());
}