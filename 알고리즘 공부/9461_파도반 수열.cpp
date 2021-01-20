#include <iostream>
using namespace std;

long long DP[101];

long long P(int n)
{
	DP[1] = 1, DP[2] = 1, DP[3] = 1, DP[4] = 2, DP[5] = 2;
	for (int i = 6; i <= n; ++i)
		DP[i] = DP[i - 1] + DP[i - 5];

	return DP[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << P(N) << '\n';
	}
	system("pause");
	return 0;
}