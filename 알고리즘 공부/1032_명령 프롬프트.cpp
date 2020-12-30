#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<string> strs(N);
	for (int i = 0; i < N; ++i) {
		cin >> strs[i];
	}

	string ret = strs[0];
	for (int i = 1; i < strs.size(); ++i)
	{
		auto rb = begin(ret);
		auto re = end(ret);
		auto sb = begin(strs[i]);
		pair<string::iterator, string::iterator> p;
		while (true) {
			p = mismatch(rb, re, sb);
			if (p.first == re) {
				break;
			}
			*p.first = '?';
			++p.first; ++p.second;
			rb = p.first;
			sb = p.second;
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}