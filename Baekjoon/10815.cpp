#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> vn;
	while (N--) {
		int n;
		cin >> n;
		vn.push_back(n);
	}
	sort(vn.begin(), vn.end());

	int M;
	cin >> M;
	while (M--) {
		int m;
		cin >> m;
		if (binary_search(vn.begin(), vn.end(), m))
			cout << '1' << ' ';
		else
			cout << '0' << ' ';
	}
	return 0;
}