#include <iostream>
#include <stack>
#include <string>
using namespace std;

void IsVPS(string& str)
{
	stack<char> brackets;
	for (auto iter = begin(str); iter != end(str); ++iter) {
		if (*iter == '(')
			brackets.push(*iter);
		else if (*iter == ')') {
			if (brackets.empty()) {
				cout << "NO" << '\n';
				return;
			}
			brackets.pop();
		}
	}
	if (!brackets.empty()) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		string input;
		cin >> input;
		IsVPS(input);
	}
	return 0;
}