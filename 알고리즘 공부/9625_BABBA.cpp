#include <iostream>
#include <vector>
#include <utility>
using namespace std;

using p = pair<int, int>;

vector<p> DP(46, make_pair(-1, -1));

p SumPair(const p& a, const p& b)
{
	return { a.first + b.first, a.second + b.second };
}

p Push(int k)
{
	if (k == 0) return make_pair(1, 0);
	if (k == 1) return make_pair(0, 1);
	if (DP[k] != make_pair(-1, -1))
		return DP[k];
	return DP[k] = SumPair(Push(k - 1), Push(k - 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	cin >> K;
	p ret = Push(K);
	cout << ret.first << " " << ret.second << '\n';
	return 0;
}