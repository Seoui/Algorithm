#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num[8];
	for (auto& n : num)
	{
		int input;
		cin >> input;
		n = input;
	}

	int ascending = 0;
	int descending = 0;
	for (int i = 0; i < 7; ++i)
	{
		if (num[i] == num[i + 1] - 1)
			ascending++;
		else if (num[i] == num[i + 1] + 1)
			descending++;
	}

	if (ascending == 7)
		cout << "ascending" << '\n';
	else if (descending == 7)
		cout << "descending" << '\n';
	else
		cout << "mixed" << '\n';

	return 0;
}