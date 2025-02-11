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

// 선택 정렬
void selectionSort(int A[], int n)
{
	/*	배열의 처음부터 마지막 원소 전까지 순회한다.
	*	순회하면서 각 인덱스를 least에 저장하고
	*	다시 해당 인덱스를 기준으로 다음 인덱스부터 배열의 끝까지 순회한다.
	*	순회하면서 만약 다음 인덱스들이 현재 인덱스보다 작다면 가장 작은 인덱스를 업데이트.
	*	최종적으로 내부 for문이 끝나면 least에는 현재 원소부터 배열의 끝 원소중 가장 작은 원소의 인덱스를 갖는다.
	*	그 다음 현재 원소와 가장 작은 원소를 스왑
	*/
	for (int i = 0; i < n - 1; ++i) {
		int least = i;
		for (int j = i + 1; j < n; ++j)
			if (A[j] < A[least]) least = j;
		swap(A[i], A[least]);
	}
}

inline int ascend(int x, int y) { return y - x; }
inline int descend(int x, int y) { return x - y; }

// 삽입 정렬
void insertionSort(int A[], int n)
{
	/*	5, 3, 8, 1, 2, 7 */

	/*	배열의 1번 인덱스부터 배열의 끝까지 순회.
	*	선택된 원소 이전 원소들중에서 삽입될 위치를 찾는다 (내부 for문)
	*	그러면서 현재 원소보다 큰 원소들은 뒤로 한 칸씩 밀려야하고 최종적으로 
	*	삽입될 위치에 현재 원소를 대입한다.
	*/
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

// 버블 정렬
void bubbleSort(int A[], int n)
{
	/*	끝 원소부터 0번 인덱스 바로 직전까지 순회, 총 n-1번 반복한다.
	*	처음에는 끝 원소인데 끝 원소에서, 다시 배열의 처음부터 끝 원소 직전까지 순회한다.
	*	만약 j번째 원소가 j+1번째 원소보다 크면 스왑. 이것을 끝 원소 직전까지 반복
	*	두 번째 외부 for문의 시퀀스는 끝 원소 직전임. 거기까지만 순회할것이라는 얘기다.
	*/
	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j)
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
	}
}

static void sortGapInsertion(int A[], int first, int last, int gap)
{
	// 삽입 정렬 수행
	// first: 배열 A에서의 부분리스트의 시작 인덱스.
	// last: 배열 A의 부분리스트의 마지막 인덱스.
	// gap: 간격
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
		// 간격이 짝수이면 1을 더해주는 것이 더 좋다는 것으로 알려져있다.
		if ((gap % 2) == 0) gap++;
		// 부분리스트의 개수는 gap과 같다. 생겨난 부분리스트를 모두 정렬.
		for (int i = 0; i < gap; ++i)
			sortGapInsertion(A, i, n - 1, gap);
	}
}

// 합병
static void merge(int A[], int left, int mid, int right)
{
	int i, j, k = left, l;
	static int sorted[1024];

	/*	sorted배열에 합병된 결과를 저장한다
	*	분리된 두 배열의 각 첫번째 원소는 i와 j가 된다. 이 분리된 두 배열을 각각 순회하면서,
	*	sorted[k] = 분리된 두 배열을 순회하면서 더 작은 값을 넣는다.
	*	두 분리된 배열중 어느 하나라도 끝이나면 for문 종료 */
	for (i = left, j = mid + 1; i <= mid && j <= right;)
		sorted[k++] = (A[i] <= A[j]) ? A[i++] : A[j++];

	/*	첫번째 배열이 먼저 끝났다면
	*	sorted에 나머지 두 번째 배열의 원소들을 넣음 */
	if (i > mid)
		for (l = j; l <= right; l++, k++)
			sorted[k] = A[l];
	/*	두 번째 배열이 먼저 끝났다면
	*	sorted에 나머지 첫 번쨰 배열의 원소들을 넣음 */
	else
		for (l = i; l <= mid; l++, k++)
			sorted[k] = A[l];
	// 합병한 sorted 배열을 A배열에 대입!
	for (l = left; l <= right; l++)
		A[l] = sorted[l];
}

// 합병 정렬
void mergeSort(int A[], int left, int right)
{
	// right가 left보다 크면 실행
	// if문 내부에서 mid로 계속 쪼개지고 있고,
	// 순환 호출을 하면서 계속 쪼개지다보면 원소의 개수가 1이게 되면 더이상 right는 left보다 크지 않다.(순환호출의 종료조건이 된다)
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

// 파티션
static int partition(int A[], int left, int right)
{
	int low = left;
	int high = right + 1;
	int pivot = A[left];
	static int i = 0;
	do {
		/*
		for (int i = 0; i <= right; ++i)
			printf("%d ", A[i]);
		printf("\n");
		for (int i = 0; i <= right; ++i) {
			if (i == low)
				printf("low");
			else if (i == high)
				printf("high");
			else
				printf(" ");
		}
		printf("\n");*/
		/* 왼쪽 리스트에서 피벗보다 큰 레코드 선택. */
		do {
			low++;
		} while (low <= right && A[low] < pivot);
		/* 오른쪽 리스트에서 피벗보다 작은 레코드 선택*/
		do {

			high--;
		} while (high >= left && A[high] > pivot);
		/* 선택된 두 레코드 스왑*/
		if (low < high)
			swap(A[low], A[high]);
		
		
	} while (low < high);// 인덱스 i, j가 엇갈리지 않는 한 반복

	// 인덱스 j가 가리키는 레코드와 피벗 교환
	swap(A[left], A[high]);
	return high;
}

// 퀵 정렬
void quickSort(int A[], int left, int right)
{
	if (left < right) {
		int q = partition(A, left, right);
		quickSort(A, left, q - 1);
		quickSort(A, q + 1, right);
	}
}

// 기수 정렬
void radixSort(int list[], int n)
{
	// 십진수의 경우 10개의 큐로 만들어진 버킷이 필요하다.
	queue<int> q[10];
	int factor = 1;
	// 각 자리수마다, d=0이면 일의 자리, d=3이면 천의 자리다.
	for (int d = 0; d < 4; ++d) {
		/*	처음은 일의 자리로 정렬해야하므로, 모든 배열의 원소들을 1로 나누고 그것의 나머지를 취한다.
		*	나머지는 결국 각 모든 원소의 일의자리만 취한 것이다. 그것을 해당 인덱스의 queue에 대입.*/
		for (int i = 0; i < n; ++i)
			q[(list[i] / factor) % 10].push(list[i]);

		int i = 0; 
		/* 10개의 큐 버킷을 순회한다 */
		for (int b = 0; b < 10; ++b)
			// 큐가 빌 때까지, 주어진 배열의 0번 인덱스부터 모든 큐에 원소들을 대입.
			while (!q[b].empty()){
				list[i++] = q[b].front();
				q[b].pop();
			}
		// for문이 끝난 결과 list에는 일의 자리로 정렬된다.
		// 다음 십의 자리로 정렬하기 위해 factor에 10을 곱해준 모습
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