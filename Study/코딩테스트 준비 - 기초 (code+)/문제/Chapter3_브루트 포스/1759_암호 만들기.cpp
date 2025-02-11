#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
vector<char> alpha;
// consonant ����
// vowel	 ����
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

// i: ������� ���ƾ� ���� ���� �Ǵ��ؾ� �ϴ� ���ĺ� �迭�� �ε���.
void go(string password, int i)
{
	if (password.length() == l) {
		if (Check(password))
			cout << password << '\n';
		return;
	}
	// ���� password�� ��������� �ʾҴµ�, �� �̻� ������ ���ڰ� ���� ���
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