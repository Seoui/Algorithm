#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string f, str;
		int n;
		cin >> f >> n >> str;
		string num;
		deque<int> deq(n);
		int index = 0;
		for (int i = 1; i < str.size(); ++i) {
			if (isdigit(str[i]))
				num += str[i];
			else if (str[i] == ',' || str[i] == ']') {
				if (num != "") {
					deq[index] = stoi(num);
					++index;
					num.clear();
				}
			}
		}

		bool popWhere = false; // false�� ��� front, true�� ��� back
		bool e = false;
		for (int i = 0; i < f.size(); ++i) {
			if (f[i] == 'R')
				popWhere = !popWhere;
			else if(f[i] == 'D') {
				if (deq.empty()) {
					cout << "error\n";
					e = true;
					break;
				}

				if (popWhere)// popWhere�� true�̸� Ȧ������.
					deq.pop_back();
				else // popWhere�� false�̸� R�� ¦������.
					deq.pop_front();
			}
		}
		
		if(e == false) {
			if (popWhere)
				reverse(begin(deq), end(deq));

			if (deq.empty())
				cout << "[]\n";
			else {
				cout << '[';
				for (int i = 0; i < deq.size() - 1; ++i)
					cout << deq[i] << ',';
				cout << deq[deq.size() - 1] << "]\n";
			}
		}
	}
	system("pause");
	return 0;
}