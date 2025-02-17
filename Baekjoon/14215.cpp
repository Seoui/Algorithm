#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int v[3] = { a, b, c };
	sort(v, v + 3);
	if (v[2] >= v[0] + v[1])
		cout << v[0] + v[1] + v[0] + v[1] - 1 << '\n';
	else
		cout << v[0] + v[1] + v[2] << '\n';
	return 0;
}