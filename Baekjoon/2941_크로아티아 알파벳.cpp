#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	vector<string> strs = {
		"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (size_t i = 0; i < strs.size(); ++i)
		for (size_t pos = str.find(strs[i]); pos != string::npos; pos = str.find(strs[i]))
			str.replace(pos, strs[i].size(), "*");
	cout << str.size();
	/*
	string str;
	cin >> str;
	// 여기서 "00"을 더해준 이유는 아래 dz= 때문이다. i가 문자열의 맨 뒤인데,
	// if문에서 str[i+1] 또는 str[i+2]로 참조하면 안된다.
	// 따라서 임시로 00으로 문자열 더해주고 for문에서 str.length()-2로 조건을 주고 있다.
	str = str + "00";
	int ret = 0;
	for (int i = 0; i < str.length() - 2; ++i) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-')
				i++;
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == 'z' || str[i + 2] == '=')
				i += 2;
			else if (str[i + 1] == '-')
				i++;
		}
		else if (str[i] == 'l') {
			if (str[i + 1] == 'j')
				i++;
		}
		else if (str[i] == 'n') {
			if (str[i + 1] == 'j')
				i++;
		}
		else if (str[i] == 's') {
			if (str[i + 1] == '=')
				i++;
		}
		else if (str[i] == 'z') {
			if (str[i + 1] == '=')
				i++;
		}
		ret++;
	}
	cout << ret;
	*/
	system("pause");
	return 0;
}