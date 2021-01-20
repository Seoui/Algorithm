#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
	if (a > b)
		return solution(b, a);
	long long answer = 0;
	for (int i = a; i <= b; ++i)
		answer += i;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a = 5;
	int b = 3;
	cout << solution(a, b);
	system("pause");
	return 0;
}