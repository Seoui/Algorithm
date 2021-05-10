#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> q;
	int N;
	cin >> N;
	while (N--) {
		int x;
		cin >> x;
		
		if (x == 0) {
			if (!q.empty()) {
				cout << q.top() << '\n';
				q.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			q.push(x);
	}
	system("pause");
	return 0;
}