#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
vector<char> alpha;
// consonant 자음
// vowel	 모음
bool Check(string& pw)
{
	int vowel = 0;
	int consonant = 0;
	for (auto& c : pw) {
		if (c == 'a' || c == 'e' ||
			c == 'i' || c == 'o' || c == 'u')
			++vowel;
		else ++consonant;
	}
	
	return vowel >= 1 && consonant >= 2;
}

// i: 사용할지 말아야 할지 이제 판단해야 하는 알파벳 배열의 인덱스.
void go(string password, int i)
{
	if (password.length() == l) {
		if (Check(password))
			cout << password << '\n';
		return;
	}
	// 아직 password가 만들어지지 않았는데, 더 이상 선택할 문자가 없는 경우
	if (i >= alpha.size()) return;

	go(password + alpha[i], i + 1);
	go(password, i + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> l >> c;
	alpha.resize(c);
	for (int i = 0; i < c; ++i)
		cin >> alpha[i];
	sort(begin(alpha), end(alpha));
	go(string(), 0);
	system("pause");
	return 0;
}