#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, k;
	vector<int> v{};
	cin >> N >> k;
	while (N--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<>{});
	cout << v[k - 1] << '\n';
	return 0;
}