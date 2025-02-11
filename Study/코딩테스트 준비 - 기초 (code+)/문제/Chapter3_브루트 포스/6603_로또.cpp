#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k = -1;
	while (k != 0) {
		cin >> k;
		vector<int> v(k);
		vector<int> select;
		for (int i = 0; i < k; ++i)
			cin >> v[i];
		for (int i = 0; i < k - 6; ++i)
			select.push_back(0);
		for (int i = 0; i < 6; ++i)
			select.push_back(1);
		vector<vector<int>> ans;
		do {
			vector<int> current;
			for (int i = 0; i < k; ++i)
				if (select[i] == 1)
					current.push_back(v[i]);
			ans.push_back(current);
		} while (next_permutation(begin(select), end(select)));
		sort(begin(ans), end(ans));
		for (auto& a : ans) {
			for (int i = 0; i < a.size(); ++i)
				cout << a[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}