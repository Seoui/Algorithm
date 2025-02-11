#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) 
{
	if (s.size() == 4 || s.size() == 6) {
		for (int i = 0; i < s.size(); ++i)
			if (s[i] - '0' < 0 || s[i] - '0' > 9)
				return false;
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s1 = "a1234";
	cout << solution(s1);
	string s2 = "1234";
	cout << solution(s2);
	system("pause");
	return 0;
}