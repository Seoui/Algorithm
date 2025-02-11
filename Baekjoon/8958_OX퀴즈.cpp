#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string ox;
	int add = 1;
	int sum = 0;

	cin >> n;
	int* output = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ox;

		for (size_t i = 0; i < ox.length(); i++)
		{
			if (ox[i] == 'O' || ox[i] == 'o')
			{
				sum += add;
				add++;
			}
			else if (ox[i] == 'X' || ox[i] == 'x')
				add = 1;
		}

		output[i] = sum;
		add = 1;
		sum = 0;
	}

	for (int i = 0; i < n; i++)
		cout << output[i] << '\n';

	delete[] output;
	return 0;
}