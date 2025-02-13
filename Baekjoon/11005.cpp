#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N, B, remain;
	string r;
	cin >> N >> B;
	while (N >= 1) {
		remain = N % B;
		N /= B;
		if (remain >= 10)
			r.push_back(remain - 10 + 'A');
		else
			r.push_back(remain + '0');
	}
	reverse(r.begin(), r.end());
	cout << r << '\n';
	return 0;
}