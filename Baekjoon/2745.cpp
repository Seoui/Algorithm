#include <string>
#include <cctype>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	//아스키 코드 [A=65 ~ Z=90]
	string N;
	int B, sum = 0;
	cin >> N >> B;
	for (int i = 0; i < N.length(); ++i) {
		if (isdigit(N[i]))
			sum += (N[i] - '0') * (pow(B, N.length() - i - 1));
		else
			sum += (N[i] - 'A' + 10) * (pow(B, N.length() - i - 1));
	}

	cout << sum << '\n';
	return 0;
}