#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void PushPop(vector<int>& seq)
{
	stack<int> stk;
	vector<char> result;
	int j = 1;
	for (auto i = begin(seq); i != end(seq); ++i) {
		while (true) {
			if (j > *i) {
				if (stk.top() != *i) {
					cout << "NO" << '\n';
					return;
				}
				stk.pop();
				result.push_back('-');
				break;
			}
			else {
				stk.push(j++);
				result.push_back('+');
			}
		}
	}
	for (auto& r : result)
		cout << r << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> seq;
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		seq.push_back(num);
	}
	PushPop(seq);
	return 0;
}
