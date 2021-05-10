#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string in;
		cin >> in;
		cout << (in[0] - '0') + (in[2] - '0') << '\n';
	}
	system("pause");
	return 0;
}