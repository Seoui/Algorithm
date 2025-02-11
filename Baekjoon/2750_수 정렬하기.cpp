#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i)
		cin >> vec[i];
	sort(begin(vec), end(vec));
	for (auto& v : vec)
		cout << v << '\n';
	return 0;
}