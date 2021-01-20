#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int sum = 0;
	sort(begin(d), end(d));
	for (int i = 0; i < d.size(); ++i) {
		sum += d[i];
		if (sum <= budget)
			++answer;
		else
			break;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solution({ 1,3,2,5,4 }, 9);
	solution({ 2,2,3,3 }, 10);
	system("pause");
	return 0;
}