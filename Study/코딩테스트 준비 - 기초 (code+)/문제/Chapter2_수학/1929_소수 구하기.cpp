#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	check[0] = check[1] = true;
	for (int i = 2; i*i <= MAX; ++i) {
		// 지워지지 않은 소수 찾으면
		if (check[i] == false) {
			// 그 소수의 배수를 다 지움
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; ++i) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}
}
/*
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int left, right;
	cin >> left >> right;
	vector<bool> prime(right + 1, true);
	prime[0] = false;
	prime[1] = false;
	for (int num = 2; num * num <= right; ++num)
		if (prime[num])
			for (long long div = (long long)pow(num, 2); div < right + 1; div += num)
				prime[div] = false;
	for (int i = left; i < right + 1; ++i)
		if (prime[i]) 
			cout << i << '\n';
	return 0;
}*/