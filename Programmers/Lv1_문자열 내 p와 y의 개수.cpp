#include <iostream>
#include <string>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int cp = 0;
	int cy = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'p' || s[i] == 'P') ++cp;
		else if (s[i] == 'y' || s[i] == 'Y') ++cy;
	}
	if (cp == 0 && cy == 0)
		return true;
	else
		return cp == cy;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s1 = "pPoooyY";
	cout << solution(s1) << '\n';
	string s2 = "PyY";
	cout << solution(s2) << '\n';
	system("pause");
	return 0;
}