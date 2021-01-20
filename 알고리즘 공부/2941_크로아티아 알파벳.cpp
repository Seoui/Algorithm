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
	// ���⼭ "00"�� ������ ������ �Ʒ� dz= �����̴�. i�� ���ڿ��� �� ���ε�,
	// if������ str[i+1] �Ǵ� str[i+2]�� �����ϸ� �ȵȴ�.
	// ���� �ӽ÷� 00���� ���ڿ� �����ְ� for������ str.length()-2�� ������ �ְ� �ִ�.
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