#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> sumSet(81);
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= a; ++i) 
		for (int j = 1; j <= b; ++j)
			for (int k = 1; k <= c; ++k) 
				++sumSet[i + j + k];

	int result = max_element(begin(sumSet), end(sumSet)) - begin(sumSet);
	cout << result;
	return 0;
}