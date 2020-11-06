#include <iostream>
using namespace std;

int GetNumOfFamily(int k, int n)
{
	if (k == 0 || n == 1)
		return n;
	return GetNumOfFamily(k, n - 1) + GetNumOfFamily(k - 1, n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase, k, n;
	cin >> testCase;
	while (testCase--)
	{
		cin >> k >> n;
		cout << GetNumOfFamily(k, n) << '\n';
	}
	system("pause");
	return 0;
}