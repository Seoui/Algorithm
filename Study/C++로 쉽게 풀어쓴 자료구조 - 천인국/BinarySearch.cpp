#include <iostream>
using namespace std;

int a[100];

int BinarySearch(int low, int high, int key)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] < key)
			low = mid + 1;
		else if (a[mid] > key)
			high = mid - 1;
		else
			return mid;
	}

	return -1;	// key not found
}

int main()
{
	for (int i = 0; i < 100; ++i)
		a[i] = i + 1;
	cout << BinarySearch(0, 99, 3);
	return 0;
}