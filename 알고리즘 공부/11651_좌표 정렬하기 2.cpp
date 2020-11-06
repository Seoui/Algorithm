#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, int>> input;
	int N;
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		input.push_back(make_pair(x, y));
	}
	sort(begin(input), end(input), Compare);
	for (auto& i : input)
		cout << i.first << " " << i.second << '\n';
	return 0;
}