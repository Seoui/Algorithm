#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool result = true;
	for (int i = 0; i < s.length() / 2; ++i) {
		if (*(s.begin() + i) != *(s.end() - i - 1)) {
			result = false;
			break;
		}
	}
	cout << result << '\n';
	return 0;
}