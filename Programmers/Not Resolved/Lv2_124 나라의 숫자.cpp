#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
	string answer = "";
	int r = 0;
	while (n) {
		r = n % 3;
		n = n / 3;
		if (r == 0) {
			answer = '4' + answer;
			n -= 1;
		}
		else if (r == 1)
			answer = '1' + answer;
		else if (r == 2)
			answer = '2' + answer;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	system("pause");
	return 0;
}