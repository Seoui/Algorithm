#include <iostream>
using namespace std;

int d[1001];

int go(int n)
{
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007;
	}
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << go(n) << endl;
	system("pause");
	return 0;
}

// ¼­ÀÇ
/*
#include <iostream>
using namespace std;

int DP[1002];

int tiling(int n)
{
	DP[1] = 1, DP[2] = 2;
	for (int i = 3; i <= n; ++i)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	
	return DP[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << tiling(n);
	return 0;
}*/