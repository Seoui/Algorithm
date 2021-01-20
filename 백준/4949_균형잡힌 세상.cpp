#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 4949 ±ÕÇüÀâÈù ¼¼»ó
void IsBalanced(string& str)
{
	vector<char> stack;
	for (auto iter = begin(str); iter != end(str); ++iter) {
		if (*iter == '(' || *iter == '[') {
			stack.push_back(*iter);
		}
		else if (*iter == ')') {
			if (stack.empty() || stack.back() != '(') {
				cout << "no" << '\n';
				return;
			}
			else
				stack.pop_back();
		}
		else if (*iter == ']') {
			if (stack.empty() || stack.back() != '[') {
				cout << "no" << '\n';
				return;
			}
			else
				stack.pop_back();
		}
	}
	if (!stack.empty()) {
		cout << "no" << '\n';
		return;
	}
	cout << "yes" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		string str;
		getline(cin, str);
		if (str == ".")
			break;
		IsBalanced(str);
	}
	return 0;
}