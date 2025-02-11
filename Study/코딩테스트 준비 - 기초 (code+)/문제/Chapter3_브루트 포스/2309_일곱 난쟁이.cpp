#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> vec(9, 0);
	int sum = 0;
	for (int i = 0; i < 9; ++i){
		cin >> vec[i];
		sum += vec[i];
	}

	sum -= 100;
	sort(begin(vec), end(vec));
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (vec[i] + vec[j] == sum) {
				for (int k = 0; k < 9; ++k){
					if (i == k || j == k) continue;
					cout << vec[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}