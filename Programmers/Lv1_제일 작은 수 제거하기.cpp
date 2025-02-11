#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
	arr.erase(min_element(begin(arr), end(arr)));
	return arr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr = { 4,3,2,1 };
	solution(arr);
	system("pause");
	return 0;
}