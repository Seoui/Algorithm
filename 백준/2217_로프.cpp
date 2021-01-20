#include <iostream>
#include <algorithm>
using namespace std;

int W[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> W[i];
	sort(W, W + N);
	int ret = 0;
	for (int i = 1; i <= N; ++i)
		ret = max(ret, W[N - i] * i);
	cout << ret;
	system("pause");
	return 0;
}