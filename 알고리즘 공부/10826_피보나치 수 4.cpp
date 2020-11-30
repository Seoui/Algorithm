#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string operator+(string str1, string str2)
{
	string ret;
	int n = 0, carry = 0;
	reverse(begin(str1), end(str1));
	reverse(begin(str2), end(str2));

	while (str1.size() < str2.size())
		str1 += "0";
	while (str2.size() < str1.size())
		str2 += "0";

	for (size_t i = 0; i < str1.size(); ++i) {
		n = ((str1[i] - '0') + (str2[i] - '0') + carry) % 10;
		ret += to_string(n);
		carry = ((str1[i] - '0') + (str2[i] - '0') + carry) / 10;
	}

	if (carry != 0)
		ret += to_string(carry);
	reverse(begin(ret), end(ret));
	return ret;
}

vector<string> dp(10001);
string Fibonacci(int n)
{
	dp[0] = "0", dp[1] = "1";
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << Fibonacci(n) << '\n';
	return 0;
}