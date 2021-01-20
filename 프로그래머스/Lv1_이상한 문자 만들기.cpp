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
		if (j % 2 == 0)		// 짝수번째 알파벳은 대문자로
			s[i] = toupper(s[i]);
		else if (j % 2 == 1)// 홀수번째 알파벳은 소문자로
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