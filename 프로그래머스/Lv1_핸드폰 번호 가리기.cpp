#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string pn)
{
	string answer = "";
	for (auto it = rbegin(pn) + 4; it != rend(pn); ++it)
		*it = '*';
	
	return pn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << solution("01033334444") << endl;
	cout << solution("027778888") << endl;
	system("pause");
	return 0;
}