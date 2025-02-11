#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<pair<int, int>> v;
	vector<int> ret(1000001);
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		v.push_back({ n, i });
	}

	sort(begin(v), end(v), less<pair<int, int>>());

	ret[v[0].second] = 0;
	int n = 1;
	for (int i = 1; i < N; ++i) {
		if (v[i].first == v[i - 1].first)
			ret[v[i].second] = n - 1;
		else
			ret[v[i].second] = n++;
	}

	for (int i = 0; i < N; ++i)
		cout << ret[i] << ' ';

	system("pause");
	return 0;
}