#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	long long ret = 0;
	for (int i = 1; i <= n; ++i)
		ret += i * (n / i);
	cout << ret << '\n';
	system("pause");
	return 0;
}