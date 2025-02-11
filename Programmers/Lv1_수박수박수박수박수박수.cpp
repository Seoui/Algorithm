#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
	string answer = "";
	bool toggle = true;
	for (int i = 0; i < n; ++i) {
		if (toggle)
			answer += "¼ö";
		else 
			answer += "¹Ú";
		toggle = !toggle;
	}
	
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 4;
	cout << solution(n);
	system("pause");
	return 0;
}