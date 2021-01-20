#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string operator+(string a, string b)
{
	string ret;
	int n = 0, carry = 0;
	reverse(begin(a), end(a));
	reverse(begin(b), end(b));

	while (a.size() < b.size())
		a += '0';
	while (a.size() > b.size())
		b += '0';

	for (size_t i = 0; i < a.size(); ++i) {
		n = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
		ret += n + '0';
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
	}

	if (carry != 0)
		ret += carry + '0';
	reverse(begin(ret), end(ret));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}