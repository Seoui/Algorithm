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
		vec[i] = i + 1;
	do {
		for (auto& v : vec)
			cout << v << " ";
		cout << '\n';
	} while (next_permutation(begin(vec), end(vec)));

	return 0;
}