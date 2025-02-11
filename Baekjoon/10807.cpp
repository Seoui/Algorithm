#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, a, v;
	vector<int> vec;
	cin >> N;
	while (N--) {
		cin >> a;
		vec.push_back(a);
	}
	cin >> v;
	cout << count(vec.begin(), vec.end(), v) << '\n';
	return 0;
}