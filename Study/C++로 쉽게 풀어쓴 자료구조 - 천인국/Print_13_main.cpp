#include <iostream>
#include <random>
#include <cstdio>
#include <queue>
using namespace std;

static void printArray(int arr[], int n, const char* str = "Array")
{
	cout << str << " = ";
	for (int i = 0; i < n; ++i) {
		cout.width(3);
		cout << arr[i];
	}
	cout << endl;
}

static void initRandom(random_device& rd, int list[], int n, int max = 100)
{
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, max);
	for (int i = 0; i < n; ++i)
		list[i] = dist(gen);
}

inline void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void selectionSort(int A[], int n)
{
	for (int i = 0; i < n - 1; ++i) {
		int least = i;
		for (int j = i + 1; j < n; ++j)
			if (A[j] < A[least]) least = j;
		swap(A[i], A[least]);
	}
}

inline int ascend(int x, int y) { return y - x; }
inline int descend(int x, int y) { return x - y; }

void insertionSort(int A[], int n)
{
	for (int i = 1; i < n; ++i) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0 && A[j] > key; --j)
			A[j + 1] = A[j];
		A[j + 1] = key;
	}
}

void insertionSortFn(int A[], int n, int (*f)(int, int))
{
	for (int i = 1; i < n; ++i) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0 && f(A[j], key) < 0; --j)
			A[j + 1] = A[j];
		A[j + 1] = key;
	}
}

void bubbleSort(int A[], int n)
{
	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j)
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
	}
}

static void sortGapInsertion(int A[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = A[i];
		for (j = i - gap; j >= first && key < A[j]; j = j - gap)
			A[j + gap] = A[j];
		A[j + gap] = key;
	}
}

void shellSort(int A[], int n)
{
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		printArray(A, n, "Shell....");
		if ((gap % 2) == 0) gap++;
		for (int i = 0; i < gap; ++i)
			sortGapInsertion(A, i, n - 1, gap);
	}
}

static void merge(int A[], int left, int mid, int right)
{
	int i, j, k = left, l;
	static int sorted[1024];

	for (i = left, j = mid + 1; i <= mid && j <= right;)
		sorted[k++] = (A[i] <= A[j]) ? A[i++] : A[j++];

	if (i > mid)
		for (l = j; l <= right; l++, k++)
			sorted[k] = A[l];
	else
		for (l = i; l <= mid; l++, k++)
			sorted[k] = A[l];

	for (l = left; l <= right; l++)
		A[l] = sorted[l];
}

void mergeSort(int A[], int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

static int partition(int A[], int left, int right)
{
	int low = left;
	int high = right + 1;
	int pivot = A[left];
	static int i = 0;
	do {
		do {
			low++;
		} while (low <= right && A[low] < pivot);

		do {

			high--;
		} while (high >= left && A[high] > pivot);
	
		if (low < high)
			swap(A[low], A[high]);
	} while (low < high);

	swap(A[left], A[high]);
	return high;
}

void quickSort(int A[], int left, int right)
{
	if (left < right) {
		int q = partition(A, left, right);
		quickSort(A, left, q - 1);
		quickSort(A, q + 1, right);
	}
}

void radixSort(int list[], int n)
{
	queue<int> q[10];
	int factor = 1;

	for (int d = 0; d < 4; ++d) {
		for (int i = 0; i < n; ++i)
			q[(list[i] / factor) % 10].push(list[i]);

		int i = 0;
		for (int b = 0; b < 10; ++b)
			while (!q[b].empty()) {
				list[i++] = q[b].front();
				q[b].pop();
			}
		factor *= 10;
		printArray(list, n, "Radix...");
	}
}

int main()
{
	int list[16];
	int n = 16;
	random_device rd;
	initRandom(rd, list, n);
	printArray(list, n, "Original ");
	selectionSort(list, n);
	printArray(list, n, "Selection ");

	cout << "==============================================================\n";

	int list2[16];
	int org[16];
	initRandom(rd, org, n);
	printArray(org, n, "Original ");

	memcpy(list2, org, n * sizeof(int));
	insertionSortFn(list2, n, ascend);
	printArray(list2, n, "Insertion-Ascend ");

	memcpy(list2, org, n * sizeof(int));
	insertionSortFn(list2, n, descend);
	printArray(list2, n, "Insertion-Descend ");

	cout << "==============================================================\n";

	int list3[16];
	initRandom(rd, list3, n);
	printArray(list3, n, "Original ");
	shellSort(list3, n);
	printArray(list3, n, "ShellSort");

	cout << "==============================================================\n";

	int list4[16];
	initRandom(rd, list4, n);
	printArray(list4, n, "Original ");
	mergeSort(list4, 0, 15);
	printArray(list4, n, "MergeSort");

	cout << "==============================================================\n";

	int list5[16];
	initRandom(rd, list5, n);
	printArray(list5, n, "Original ");
	quickSort(list5, 0, 15);
	printArray(list4, n, "QuickSort");

	cout << "==============================================================\n";

	int list6[16];
	initRandom(rd, list6, n);
	printArray(list6, n, "Original");
	radixSort(list6, n);
	printArray(list4, n, "RadixSort");

	cout << "==============================================================\n";

	int list7[8] = { 67, 90, 57, 25, 84, 32, 73, 54 };
	printArray(list7, 8, "Original");
	quickSort(list7, 0, 7);
	printArray(list7, 8, "QuickSort");
}