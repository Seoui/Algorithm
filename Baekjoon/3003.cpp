#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> set{ 1,1,2,2,2,8 };
	vector<int> vec;
	int N = 6;
	for (int i = 0; i < 6; ++i) {
		int a;
		cin >> a;
		vec.push_back(set[i] - a);
	}

	for (int v : vec)
		cout << v << ' ';
	cout << '\n';
	return 0;
}