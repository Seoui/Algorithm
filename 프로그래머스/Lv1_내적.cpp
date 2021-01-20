#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
	int answer = 0;
	return inner_product(begin(a), end(a), begin(b), answer);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> a = { 1,2,3,4 };
	vector<int> b = { -3, -1, 0, 2 };
	cout << solution(a, b);

	cout << '\n';

	vector<int> c = { -1, 0, 1 };
	vector<int> d = { 1, 0, -1 };
	cout << solution(c, d);

	system("pause");
	return 0;
}