#include <iostream>
using namespace std;

// 재귀
int bino(int n, int r) // 이항계수: binomial coefficient
{
	// 기저 사례: n = r (모든 원소를 다 고르는 경우) 혹은 r = 0 (고를 원소가 없는 경우)
	if (r == 0 || n == r) return 1;
	return bino(n - 1, r - 1) + bino(n - 1, r);
}

// 동적계획법
int cache[30][30];
int bino2(int n, int r)
{
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1)
		return cache[n][r];
	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	system("pause");
	return 0;
}