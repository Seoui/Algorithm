#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ret = 0;
	int num = 0;
	string nums = "";
	cin >> num >> nums;
	for (int i = 0; i < num; ++i)
	{
		int n = nums[i] - '0';
		ret += n;
	}
	cout << ret << "\n";
	return 0;
}