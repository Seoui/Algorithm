#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[9];
	int max = 0;
	int index = 0;

	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	cout << max << "\n" << index + 1;

	return 0;
}