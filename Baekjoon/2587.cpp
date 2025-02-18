#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v{};
	for (int i = 0; i < 5; ++i) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int s = accumulate(v.begin(), v.end(), 0);
	cout << s / 5 << '\n' << v[2] << '\n';
	return 0;
}