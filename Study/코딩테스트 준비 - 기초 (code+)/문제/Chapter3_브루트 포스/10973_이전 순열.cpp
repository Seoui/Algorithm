#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
		cin >> vec[i];
	if (prev_permutation(begin(vec), end(vec)))
		for (auto& v : vec)
			cout << v << " ";
	else
		cout << -1;

	return 0;
}