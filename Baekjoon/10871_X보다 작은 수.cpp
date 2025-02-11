#include <iostream>
#include <vector> 
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, b, c;
	cin >> a >> b;
	for (int i = 0; i < a; ++i)
	{
		cin >> c;
		if (c < b)
			cout << c << " ";
	}
	return 0;
}