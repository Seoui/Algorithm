#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> stack;
	int N;
	cin >> N;
	vector<string> commands;
	vector<int> pushNums;
	while (N--) {
		string comd;
		cin >> comd;
		if (comd == "push") {
			int num;
			cin >> num;
			pushNums.push_back(num);
		}
		commands.push_back(comd);
	}
	int i = 0;
	for (auto& c : commands)
	{
		if (c == "push")
			stack.push_back(pushNums[i++]);
		else if (c == "top") {
			if (!stack.empty())
				cout << stack.back() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (c == "size")
			cout << (int)stack.size() << '\n';
		else if (c == "empty")
			cout << stack.empty() << '\n';
		else if (c == "pop") {
			if (!stack.empty())
			{
				int n = stack.back();
				stack.pop_back();
				cout << n << '\n';
			}
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}