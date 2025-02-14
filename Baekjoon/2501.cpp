#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> f;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		if (N % i == 0)
			f.push_back(i);
	if (f.size() < K)
		cout << 0 << '\n';
	else
		cout << f[K - 1] << '\n';
	return 0;
}