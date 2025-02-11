#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int> hp;
	int N;
	cin >> N;
	while (N--) {
		int Z;
		cin >> Z;
		if (Z == 0) {
			if (hp.empty())
				cout << 0 << '\n';
			else {
				cout << hp.top() << '\n';
				hp.pop();
			}
		}
		else {
			hp.push(Z);
		}
	}
	system("pause");
	return 0;
}