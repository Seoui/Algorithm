#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s) 
{
	string answer = "";
	if (s.size() % 2 == 0)
		answer = s[s.size() / 2 - 1];
	answer += s[s.size() / 2];
	
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s = "qwer";
	cout << solution(s);
	system("pause");
	return 0;
}