#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	stack<char> s;
	string p;//parenthesis
	size_t steel = 0;
	cin >> p;
	for (size_t i = 0; i < p.length(); ++i) {
		if (p[i] == '(') {
			s.push(p[i]);
			++steel;
		}
		else if (p[i] == ')') {
			if (p[i - 1] == '(') {
				s.pop();
				--steel;
				steel = steel + s.size();
			}
			else
				s.pop();
		}
	}
	cout << steel << '\n';
	return 0;
}