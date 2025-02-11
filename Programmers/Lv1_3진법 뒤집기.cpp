#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) 
{
	int answer = 0;
	const int len = int(log(n) / log(3)) + 1;

	while (n != 0) {
		int log3n = int(log(n) / log(3));
		answer += int(pow(3, len - log3n - 1));
		n -= int(pow(3, log3n));
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 45;
	cout << solution(n) << endl;
	system("pause");
	return 0;
}