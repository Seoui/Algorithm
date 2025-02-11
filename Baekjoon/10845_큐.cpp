#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> queue;
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
			queue.push_back(pushNums[i++]);
		else if (c == "front") {
			if (!queue.empty())
				cout << queue.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (c == "back") {
			if (!queue.empty())
				cout << queue.back() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (c == "size")
			cout << (int)queue.size() << '\n';
		else if (c == "empty")
			cout << queue.empty() << '\n';
		else if (c == "pop") {
			if (!queue.empty())
			{
				int n = queue.front();
				queue.erase(begin(queue));
				cout << n << '\n';
			}
			else
				cout << -1 << '\n';
		}
	}
	system("pause");
	return 0;
}