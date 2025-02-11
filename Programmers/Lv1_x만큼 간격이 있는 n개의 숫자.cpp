#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(int x, int n) 
{
	vector<long long> answer;
	long long l = 0;
	for (int i = 0; i < n; ++i) {
		l += x;
		answer.push_back(l);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution(2, 5);
	solution(4, 3);
	solution(-4, 2);
	system("pause");
	return 0;
}