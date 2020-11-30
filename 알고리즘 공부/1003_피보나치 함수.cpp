#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using p = pair<int, int>;
vector<p> f(41, make_pair(0, 0));

p operator+(p& a, p& b) 
{
	return{ a.first + b.first, a.second + b.second };
}

p CallCountFibonacci(int n)
{
	f[0] = make_pair(1, 0);
	f[1] = make_pair(0, 1);
	f[2] = make_pair(1, 1);
	for (int i = 3; i <= n; ++i)
		f[i] = f[i - 1] + f[i - 2];
	return f[n];
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
		p ret = CallCountFibonacci(N);
		cout << ret.first << " " << ret.second << '\n';
	}
	return 0;
}