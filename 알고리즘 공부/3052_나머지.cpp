#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[10] =
	{ -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 };
	int count = 0;
	int size = 10;

	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
		arr[i] = arr[i] % 42;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] == arr[j])
			{
				arr[i] = -1;
				i--;
				size--;
				break;
			}
		}
	}

	for (auto& i : arr)
		if (i != -1)
			count++;

	cout << count << '\n';
	return 0;
}