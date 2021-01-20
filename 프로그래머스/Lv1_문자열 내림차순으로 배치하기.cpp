#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
	string answer;
	sort(begin(s), end(s), greater<char>());
	return answer = s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s = "Zbcdefg";
	cout << solution(s);
	system("pause");
	return 0;
}