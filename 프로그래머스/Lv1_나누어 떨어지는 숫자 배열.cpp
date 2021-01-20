#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
	vector<int> answer;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] % divisor == 0)
			answer.push_back(arr[i]);
	}
	if (answer.empty())
		answer.push_back(-1);
	else
		sort(begin(answer), end(answer));
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr1 = { 5, 9, 7, 10 };
	int div1 = 5;
	vector<int> ret1 = solution(arr1, div1);
	for (auto& r1 : ret1)
		cout << r1 << ' ';
	cout << '\n';

	vector<int> arr2 = { 2, 36, 1, 3 };
	int div2 = 1;
	vector<int> ret2 = solution(arr2, div2);
	for (auto& r2 : ret2)
		cout << r2 << ' ';
	cout << '\n';

	vector<int> arr3 = { 3, 2, 6 };
	int div3 = 10;
	vector<int> ret3 = solution(arr3, div3);
	for (auto& r3 : ret3)
		cout << r3 << ' ';
	cout << '\n';

	system("pause");
	return 0;
}