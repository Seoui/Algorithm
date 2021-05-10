#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string in;
	cin >> in;
	sort(begin(in), end(in), greater<int>());
	cout << in;
	return 0;
}