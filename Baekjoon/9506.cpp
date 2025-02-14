#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	while (1) {
		int n, s = 0;
		vector<int> f{};
		string result{};
		cin >> n;
		if (n == -1) break;

		for (int i = 1; i < n; ++i) {
			if (n % i == 0)
				f.push_back(i);
		}

		s = accumulate(f.begin(), f.end(), 0);

		if (n == s) {
			result.append(to_string(n));
			result.append(" = ");
			for (int j = 0; j < f.size(); ++j) {
				if (j + 1 == f.size()) {
					result.append(to_string(f[j]));
				}
				else {
					result.append(to_string(f[j]));
					result.append(" + ");
				}
			}
			cout << result << '\n';
		}
		else {
			cout << n << " is NOT perfect." << '\n';
		}
	}
	return 0;
}