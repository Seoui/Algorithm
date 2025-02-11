#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) 
{
	long long answer = 0;
	string num = to_string(n);
	int len = num.size();

	int no = 0;
	if(len % 2 == 0)
		no = len / 2;
	else
		no = len / 2 + 1;

	for (long long i = (long long)pow(10, no - 1); i < (long long)pow(10, no); ++i){
		if (i*i == n) {
			answer = (i + 1) * (i + 1);
			break;
		}
	}

	if (answer == 0)
		answer = -1;

	/*
		간단하게 풀 수 있었다..

		long long answer = sqrt(n);

		return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
	
	*/
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n1 = 121;
	cout << solution(n1) << endl;

	long long n2 = 3;
	cout << solution(n2) << endl;
	system("pause");
	return 0;
}