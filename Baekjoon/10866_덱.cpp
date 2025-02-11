#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> deque;
	int N;
	cin >> N;
	vector<string> commands;
	vector<int> pushNums;
	while (N--) {
		string comd;
		cin >> comd;
		if (comd == "push_front" || comd == "push_back") {
			int num;
			cin >> num;
			pushNums.push_back(num);
		}
		commands.push_back(comd);
	}
	int i = 0;
	for (auto& c : commands)
	{
		if (c == "push_front")
			deque.insert(begin(deque), pushNums[i++]);
		else if (c == "push_back")
			deque.push_back(pushNums[i++]);
		else if (c == "front") {
			if (!deque.empty())
				cout << deque.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (c == "back") {
			if (!deque.empty())
				cout << deque.back() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (c == "size")
			cout << (int)deque.size() << '\n';
		else if (c == "empty")
			cout << deque.empty() << '\n';
		else if (c == "pop_front") {
			if (!deque.empty()) {
				int n = deque.front();
				deque.erase(begin(deque));
				cout << n << '\n';
			}
			else
				cout << -1 << '\n';
		}
		else if (c == "pop_back") {
			if (!deque.empty()) {
				int n = deque.back();
				deque.pop_back();
				cout << n << '\n';
			}
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}