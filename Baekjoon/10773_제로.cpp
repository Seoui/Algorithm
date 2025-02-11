#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> stack;
	int K;
	cin >> K;
	while (K--) {
		int num;
		cin >> num;
		if (num == 0)
			stack.pop_back();
		else
			stack.push_back(num);
	}
	cout << accumulate(begin(stack), end(stack), 0) << '\n';
	return 0;
}