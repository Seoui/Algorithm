#include <iostream>
#include <numeric>
#include <limits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[5]{};
	for (int i = 0; i < 5; ++i)
		cin >> arr[i];
	int result = numeric_limits<int>::max();
	for (int i = 0; i < 5; ++i){
		for (int j = i + 1; j < 5; ++j){
			for (int k = j + 1; k < 5; ++k) {
				int tmpgcd = lcm(lcm(arr[i], arr[j]), arr[k]);
				result = result > tmpgcd ? tmpgcd : result;
			}
		}
	}
	cout << result;
	return 0;
}