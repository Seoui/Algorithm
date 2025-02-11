#include <iostream>
#include <utility>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	vector<pair<int, int>> pos;
	cin >> t;
	while (t--) {
		cin >> n;
		pos.resize(n + 2);
		for (int i = 0; i < n + 2; ++i)
			cin >> pos[i].first >> pos[i].second;


	}
	system("pause");
	return 0;
}