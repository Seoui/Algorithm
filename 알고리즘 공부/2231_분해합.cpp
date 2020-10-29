#include <iostream>
#include <string>
using namespace std;

int digitSum(int num)
{
	string num_str = to_string(num);
	int digit_sum = 0;
	for (auto i = begin(num_str); i != end(num_str); ++i)
		digit_sum += *i - 48;
	digit_sum += num;
	return digit_sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	int num = 1;
	cin >> input;
	while (true) {
		if (input == digitSum(num)) {
			cout << num << '\n';
			break;
		}
		else if (num > 1000000) {
			cout << 0 << '\n';
			break;
		}
		else
			num++;
	}
	return 0;
}