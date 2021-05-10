#include <iostream>
#include <limits>
using namespace std;

int n;
int minr = numeric_limits<int>::max();
int maxr = numeric_limits<int>::min();
int arr[12];
int oper[4];

void solution(int k, int result)
{
	if (k == n - 1) {
		if (minr > result) minr = result;
		if (maxr < result) maxr = result;
		return;
	}

	if(oper[0] > 0) {
		--oper[0];
		solution(k + 1, result + arr[k + 1]);
		++oper[0];
	}
	if(oper[1] > 0) {
		--oper[1];
		solution(k + 1, result - arr[k + 1]);
		++oper[1];
	}
	if(oper[2] > 0){
		--oper[2];
		solution(k + 1, result * arr[k + 1]);
		++oper[2];
	}
	if (oper[3] > 0) {
		--oper[3];
		solution(k + 1, result / arr[k + 1]);
		++oper[3];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i)
		cin >> oper[i];

	solution(0, arr[0]);
	cout << maxr << '\n' << minr << '\n';
	return 0;
}