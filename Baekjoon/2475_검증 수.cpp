#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int unique_num[5];
	int result = 0;

	for (auto& u : unique_num)
	{
		int input;
		cin >> input;
		u = input;
		result += input * input;
	}

	cout << result % 10 << '\n';

	return 0;
}