#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> v{};
	int N, M;
	cin >> N >> M;
	while (N--) {
		string sn;
		cin >> sn;
		v.push_back(sn);
	}
	sort(v.begin(), v.end());

	int result = 0;
	while (M--) {
		string sm;
		cin >> sm;
		if (binary_search(v.begin(), v.end(), sm))
			result++;
	}

	cout << result << '\n';
	return 0;
}