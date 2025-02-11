#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

double solution(vector<int> arr) 
{
	double answer = 0;
	answer = accumulate(begin(arr), end(arr), answer);
	answer /= arr.size();
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << solution({ 1,2,3,4 }) << endl;
	cout << solution({ 5, 5 });
	system("pause");
	return 0;
}