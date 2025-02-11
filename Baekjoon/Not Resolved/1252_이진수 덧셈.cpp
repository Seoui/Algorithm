#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string left;
	string right;
	cin >> left >> right;

	// 두 문자열의 길이
	int ll = left.length();
	int rl = right.length();

	// 긴 문자열의 길이
	int lLength = ll > rl ? ll : rl;
	
	string answer;
	answer.resize(lLength);

	reverse(begin(left), end(left));
	reverse(begin(right), end(right));
	
	// 짧은 쪽의 스트링에 0을 차이만큼 붙여줘야 한다.
	if (ll > rl) {
		for (int i = 0; i < ll - rl; ++i)
			right += '0';
	}
	else if (rl > ll) {
		for (int i = 0; i < rl - ll; ++i)
			left += '0';
	}

	bool carry = false;
	for (int i = 0; i < lLength; ++i) {
		if (left[i] == '1' && right[i] == '1') {
			if (carry)
				answer[i] = '1';
			else
				answer[i] = '0';
			carry = true;
		}
		else if(left[i] == '0' && right[i] == '0') {
			if (carry)
				answer[i] = '1';
			else
				answer[i] = '0';
			carry = false;
		}
		else {
			if (carry) {
				answer[i] = '0';
				carry = true;
			}
			else {
				answer[i] = '1';
				carry = false;
			}
		}
	}
	if (carry)
		answer += '1';
	reverse(begin(answer), end(answer));
	while (answer[0] == '0')
		answer.erase(begin(answer));
	if (answer.empty())
		cout << 0 << '\n';
	else
		cout << answer << endl;
	system("pause");
	return 0;
}