#include "Heap.h"
#include "PriorityQueue.h"
#include <random>
#include <queue>
using namespace std;

// STL 우선순위 큐를 이용한 내림차순 정렬. 최대 힙 사용
void heapSortDec(int a[], int n)
{
	priority_queue<int> maxHeap;
	for (int i = 0; i < n; ++i)
		maxHeap.push(a[i]);
	for (int i = 0; i < n; ++i) {
		a[i] = maxHeap.top();
		maxHeap.pop();
	}
}

// STL 우선순위 큐를 이용한 오름차순 정렬. 최소 힙 사용
void heapSortInc(int a[], int n)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < n; ++i)
		minHeap.push(a[i]);
	for (int i = 0; i < n; ++i) {
		a[i] = minHeap.top();
		minHeap.pop();
	}
}

void heapSort(int a[], int n)
{
	MaxHeap h;
	for (int i = 0; i < n; ++i)
		h.insert(a[i]);
	for (int i = n - 1; i >= 0; --i)
		a[i] = h.remove().getKey();
}

void MakeTree(int freq[], int n)
{
	MinHeap heap;
	for (int i = 0; i < n; ++i)
		heap.insert(freq[i]);

	for (int i = 1; i < n; ++i) {
		HeapNode e1 = heap.remove();
		HeapNode e2 = heap.remove();
		heap.insert(e1.getKey() + e2.getKey());
		printf(" (%d+%d)\n", e1.getKey(), e2.getKey());
	}
}

bool isHeapRecur(int a[], int i, int n)
{
	if (i >= (n - 2) / 2)
		return true;

	if (a[i] >= a[2 * i + 1] &&
		a[i] >= a[2 * i + 2] &&
		isHeapRecur(a, 2 * i + 1, n) &&
		isHeapRecur(a, 2 * i + 2, n))
		return true;
	
	return false;
}

bool isHeapIter(int a[], int n)
{
	for (int i = 0; i <= (n - 2) / 2; ++i) {
		if (a[2 * i + 1] > a[i])
			return false;
		if (2 * i + 2 < n && a[2 * i + 2] > a[i])
			return false;
	}
	return true;
}

int main()
{
	MaxHeap heap;

	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(3);
	heap.insert(7);
	heap.display();

	heap.remove();
	heap.display();
	heap.remove();
	heap.display();
	printf("\n------------------------------------");

	MaxHeap heap2;
	int data[10];
	int data2[10];
	int data3[10];
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);
	for (int i = 0; i < 10; ++i) {
		int r = dis(gen);
		data[i] = r;
		data2[i] = r;
		data3[i] = r;
	}
	printf("\n정렬 전: ");
	for (int i = 0; i < 10; ++i)
		printf("%3d ", data[i]);
	heapSort(data, 10);
	printf("\nheapSort 정렬 후: ");
	for (int i = 0; i < 10; ++i)
		printf("%3d ", data[i]);
	heapSortDec(data2, 10);
	printf("\nheapSortDec 정렬 후: ");
	for (int i = 0; i < 10; ++i)
		printf("%3d ", data2[i]);
	heapSortInc(data3, 10);
	printf("\nheapSortInc 정렬 후: ");
	for (int i = 0; i < 10; ++i)
		printf("%3d ", data3[i]);
	printf("\n------------------------------------\n");

	int freq[] = { 15, 12, 8, 6, 4 };
	MakeTree(freq, 5);

	printf("\n------------------------------------\n");

	MaxPriorityQueue q1;
	q1.insert(1);
	q1.insert(100);
	q1.insert(28);
	q1.insert(55);
	q1.insert(7);
	q1.insert(40);
	q1.insert(81);
	q1.display();
	q1.remove();
	q1.display();
	q1.remove();
	q1.display();
	q1.remove();
	q1.display();

	printf("\n------------------------------------\n");
	MinPriorityQueue q2;
	q2.insert(30);
	q2.insert(5);
	q2.insert(10);
	q2.insert(15);
	q2.insert(70);
	q2.insert(40);
	q2.insert(70);
	q2.display();

	q2.remove();
	q2.display();
	q2.remove();
	q2.display();
	q2.remove();
	q2.display();
	printf("\n------------------------------------\n");
	printf("\nmax heap인지 검사\n");
	int t1[] = { 7, 5, 6, 3, 4, 3, 2, 2, 1 }; // max heap
	printf("t1 is Heap?(Recur): %d\n", isHeapRecur(t1, 0, 9));
	printf("t1 is Heap?(Iter): %d\n", isHeapIter(t1, 9));

	int t2[] = { 9,7,6,5,4,3,2,2,1,3 };
	printf("t2 is Heap?(Recur): %d\n", isHeapRecur(t2, 0, 10));
	printf("t2 is Heap?(Iter): %d\n", isHeapIter(t2, 10));

	int t3[] = { 1,2 ,3, 4, 5 };
	printf("t3 is Heap?(Recur): %d\n", isHeapRecur(t3, 0, 5));
	printf("t3 is Heap?(Iter): %d\n", isHeapIter(t3, 5));
	int b = 5;
}