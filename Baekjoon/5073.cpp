#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while (true) {
		int a, b, c;
		int mn = 0;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		int v[3] = { a, b, c };
		sort(v, v + 3);
		if (v[2] >= v[0] + v[1])
			cout << "Invalid\n";
		else {
			if (v[0] == v[1] && v[0] == v[2] && v[1] == v[2])
				cout << "Equilateral\n";
			else if (v[0] == v[1] || v[0] == v[2] || v[1] == v[2])
				cout << "Isosceles\n";
			else
				cout << "Scalene\n";
		}
	}
	return 0;
}