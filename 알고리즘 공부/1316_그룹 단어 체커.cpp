#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool presented[26];

bool Check(string& str)
{
	bool ret = true;
	presented[str[0] - 'a'] = true;
	char cur = str[0];
	for (size_t i = 1; i < str.length(); ++i) {
		if (cur != str[i]) {
			if (presented[str[i] - 'a']) {// 이미 등장했었다면
				ret = false;
				break;
			}
			else {	//등장하지 않았었다면
				presented[str[i] - 'a'] = true;
			}
		}
		cur = str[i];
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, ret = 0;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		ret += Check(str);
		fill(presented, presented + 26, 0);
	}
	cout << ret;
	return 0;
}