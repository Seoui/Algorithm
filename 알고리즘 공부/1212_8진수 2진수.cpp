#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string t[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string num;
	cin >> num;
	string ret;
	for (int i = 0; i < num.size(); ++i)
		ret += t[num[i] - '0'];
	size_t pos = ret.find('1');
	if (pos == string::npos) {
		cout << 0;
		return 0;
	}
	ret = ret.substr(pos, ret.length());
	cout << ret;
	return 0;
}