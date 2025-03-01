#include <iostream>
using namespace std;

int ar[100];

int ternary_search(int l, int r, int x)
{
	if (r >= 1)
	{
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (ar[mid1] == x)
			return mid1;
		if (ar[mid2] == x)
			return mid2;

		if (x < ar[mid1])
			return ternary_search(l, mid1 - 1, x);
		else if (x > ar[mid2])
			return ternary_search(mid2 + 1, r, x);
		else
			return ternary_search(mid1 + 1, mid2 - 1, x);
	}
	return -1;
}

int main()
{
	for (int i = 0; i < 100; ++i)
		ar[i] = i + 1;
	cout << ternary_search(0, 99, 10);
	system("pause");
	return 0;
}