#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, int>> table;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		pair<int, int> a;
		cin >> a.first >> a.second;
		table.push_back(a);
	}
	sort(begin(table), end(table), compare);
	int ret = 0;
	int t = 0;
	for (int i = 0; i < N; ++i) {
		if (t > table[i].first)
			continue;
		ret++;
		t = table[i].second;
	}
	cout << ret << '\n';
	return 0;
}