#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
	int j = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			j = 0;
			continue;
		}
		if (j % 2 == 0)		// ¦����° ���ĺ��� �빮�ڷ�
			s[i] = toupper(s[i]);
		else if (j % 2 == 1)// Ȧ����° ���ĺ��� �ҹ��ڷ�
			s[i] = tolower(s[i]);
		++j;
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s = "try hello world";
	cout <<	solution(s);
	system("pause");
	return 0;
}