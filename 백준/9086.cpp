#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string S;
	cin >> T;
	while (T--) {
		cin >> S;
		cout << S.front() << S.back() << '\n';
	}
	return 0;
}