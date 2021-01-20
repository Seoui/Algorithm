#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> vec;
	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(begin(vec), end(vec));
	for (auto& v : vec)
		cout << v << '\n';
	return 0;
}