#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n)
{
	int answer = 0;
	for (int i = 1; i <= sqrt(n); ++i)
		if (n%i == 0) {
			answer += i;
			if (n != i * i)
				answer += n / i;
		}

	/* 두 번째 버전
	for (int i = 1; i <= n; ++i)
		if (n%i == 0)
			answer += i;
			*/
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n1 = 12;
	cout << solution(n1) << endl;

	int n2 = 5;
	cout << solution(n2) << endl;
	system("pause");
	return 0;
}