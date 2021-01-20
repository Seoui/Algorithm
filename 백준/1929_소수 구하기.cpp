#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int left, right;
	cin >> left >> right;
	vector<bool> prime(right + 1, true);
	prime[0] = false;
	prime[1] = false;
	for (int num = 2; num * num <= right; ++num)
		if (prime[num])
			for (long long div = (long long)pow(num, 2); div < right + 1; div += num)
				prime[div] = false;
	for (int i = left; i < right + 1; ++i)
		if (prime[i]) 
			cout << i << '\n';
	return 0;
}