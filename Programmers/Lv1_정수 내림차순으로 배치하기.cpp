#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) 
{
	long long answer = 0;
	string num = to_string(n);
	sort(begin(num), end(num), greater<char>());
	answer = stoll(num);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 118372;
	cout << solution(n);
	system("pause");
	return 0;
}