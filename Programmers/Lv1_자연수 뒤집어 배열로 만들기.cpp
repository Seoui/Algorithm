#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) 
{
	vector<int> answer;
	string num = to_string(n);
	for (auto it = rbegin(num); it != rend(num); ++it)
		answer.push_back(*it-'0');
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n = 12345;
	solution(n);
	system("pause");
	return 0;
}