#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, F;
	cin >> N >> F;

	int r = N % 100;
	int start = N - r;
	int end = start + 100;
	for (int i = start; i < end; i++) {
		if (i % F == 0) {
			string n = to_string(i);
			cout << n.substr(n.length() - 2, n.length()) << '\n';
			break;
		}
	}
	system("pause");
	return 0;
}