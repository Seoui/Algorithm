#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	stack<char> stk;
	string p;
	bool isCan = true;
	int sum = 0, tmp = 1;
	cin >> p;
	if (p[0] == '(' || p[0] == '[')
		stk.push(p[0]);
	else {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < p.length(); i++) {
		if (p[i] == '(') {
			tmp *= 2;
			stk.push('(');
		}
		else if (p[i] == '[') {
			tmp *= 3;
			stk.push('[');
		}
		else if (p[i] == ')') {
			if (p[i - 1] == '(')
				sum += tmp;
			if (stk.empty()) {
				isCan = false;
				break;
			}
			if (stk.top() == '(')
				stk.pop();
			tmp /= 2;
		}
		else if (p[i] == ']') {
			if (p[i - 1] == '[')
				sum += tmp;
			if (stk.empty()) {
				isCan = false;
				break;
			}
			if (stk.top() == '[')
				stk.pop();
			tmp /= 3;
		}
	}
	if (isCan)
		cout << stk.empty() ? sum : 0 << '\n';
	else
		cout << 0;
	system("pause");
	return 0;
}