#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b)
{
	return a == 0 ? b
		: b == 0 ? a
		: GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> v;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long result = 0;
		while (n--) {
			int num;
			cin >> num;
			for (int i = 0; i < v.size(); ++i)
				result += GCD(v[i], num);
			v.push_back(num);
		}
		cout << result << '\n';
		v.clear();
	}
	return 0;
}