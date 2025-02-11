#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ' ') { // 문자일 때
			// 대문자일 경우
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = (s[i] - 'A' + n) % 26 + 'A';
			// 소문자일 경우
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = (s[i] - 'a' + n) % 26 + 'a';
		}
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s1 = "AB";
	int n1 = 1;
	cout << solution(s1, n1) << '\n';
	string s2 = "z";
	int n2 = 1;
	cout << solution(s2, n2) << '\n';

	string s3 = "a B z";
	int n3 = 4;
	cout << solution(s3, n3) << '\n';

	system("pause");
	return 0;
}