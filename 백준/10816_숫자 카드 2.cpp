#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unordered_map<int, int> m;
	int N, M;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		auto iter = m.find(num);
		if (iter != end(m)) {
			++(*iter).second;
		}
		else
			m.insert(make_pair(num, 1));
	}
	cin >> M;
	vector<int> result;
	while (M--) {
		int num;
		cin >> num;
		auto iter = m.find(num);
		if (iter != end(m))
			result.push_back((*iter).second);
		else
			result.push_back(0);
	}
	for (auto& r : result)
		cout << r << " ";
	cout << '\n';
	return 0;
}