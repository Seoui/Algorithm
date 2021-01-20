#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

vector<int> solution(int n, int m) 
{
	vector<int> answer;
	answer.push_back(gcd(n, m));
	answer.push_back(lcm(n, m));
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