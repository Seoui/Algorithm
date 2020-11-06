#include <iostream>
#include <cstring>
using namespace std;

// 메모이제이션 기법
int cache[11][11];
int Combination(int N, int K)
{
	if (K == 0 || N == K) return 1;
	if (cache[N][K] != -1) return cache[N][K];
	return cache[N][K] = Combination(N - 1, K - 1) + Combination(N - 1, K);
}

// 일반
int Combination2(int N, int K)
{
	if (K == 0 || N == K) return 1;
	return Combination2(N - 1, K - 1) + Combination2(N - 1, K);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(cache, -1, sizeof(cache));
	int N, K;
	cin >> N >> K;
	cout << Combination(N, K) << '\n';
	cout << Combination2(N, K) << '\n';
	system("pause");
	return 0;
}