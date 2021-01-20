#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer(begin(arr), unique(begin(arr), end(arr)));
	
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr1 = { 1, 1, 3, 3, 0, 1, 1 };
	vector<int> arr2 = { 4, 4, 4, 3, 3 };
	auto ret1 = solution(arr1);
	auto ret2 = solution(arr2);

	for (auto& r1 : ret1)
		cout << r1 << ' ';
	cout << '\n';
	for (auto& r2 : ret2)
		cout << r2 << ' ';
	cout << '\n';
	system("pause");
	return 0;
}