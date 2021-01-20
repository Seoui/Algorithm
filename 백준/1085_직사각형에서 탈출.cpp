#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	//╩С, го
	int mdh = min(h - y, y);
	//аб, ©Л
	int mdw = min(w - x, x);
	cout << min(mdh, mdw) << '\n';
	return 0;
}