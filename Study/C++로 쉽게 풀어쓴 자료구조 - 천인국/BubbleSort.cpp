#include <iostream>
using namespace std;

void bubble_sort(int A[], int n) 
{
	int temp;
	for (int k = 0; k < n - 1; ++k) {
		// (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

		for (int i = 0; i < n - k - 1; ++i) {
			if (A[i] > A[i + 1]) {
				// here swapping of positions is being done.
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[100];
	for (int i = 0; i < 100; ++i)
		arr[i] = 1000 - i;
	bubble_sort(arr, 100);
	for (int i = 0; i < 100; ++i)
		cout << arr[i] << ' ';

	system("pause");
	return 0;
}