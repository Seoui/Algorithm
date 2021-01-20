#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	if (s[0] == '-')
		return -stoi(s.substr(1, s.size()));
	else if (s[0] == '+')
		return stoi(s.substr(1, s.size()));
	else
		return stoi(s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s = "-1234";
	cout << solution(s);
	system("pause");
	return 0;
}