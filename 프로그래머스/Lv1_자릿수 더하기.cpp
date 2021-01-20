#include <iostream>
#include <string>
using namespace std;

int solution(int n)
{
	int answer = 0;
	string num = to_string(n);
	for (int i = 0; i < num.size(); ++i)
		answer += num[i] - '0';
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N1 = 123;
	cout << solution(N1) << endl;

	int N2 = 987;
	cout << solution(N2) << endl;
	system("pause");
	return 0;
}