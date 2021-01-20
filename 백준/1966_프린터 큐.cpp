#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void numberMinutes(vector<pair<int, int>>& q, int M)
{
	int result = 1;
	while (true) {
		if (q.size() == 1) break;
		auto maxPriority = max_element(begin(q), end(q),
			[](pair<int, int> a, pair<int, int> b) {
			if (a.first < b.first) return true;
			else return false;
		});
		int maxPos = static_cast<int>(maxPriority - begin(q));
		for (int i = 0; i < maxPos; ++i) {
			q.push_back(q.front());
			q.erase(begin(q));
		}
		if (q.front().second == M) break;
		q.erase(begin(q));
		++result;
	}
	cout << result << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<pair<int, int>> q;
	int T;
	cin >> T;
	while (T--) {
		int N, M, pos = 0;
		cin >> N >> M;
		while (N--) {
			int priority;
			cin >> priority;
			q.push_back(make_pair(priority, pos++));
		}
		numberMinutes(q, M);
		q.clear();
	}
	return 0;
}