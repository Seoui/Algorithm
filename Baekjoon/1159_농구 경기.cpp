#include <iostream>
#include <string>
using namespace std;

int alpha[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		string f;
		cin >> f;
		alpha[f[0] - 'a']++;
	}
	string ret;
	for (int i = 0; i < 26; ++i) {
		if (alpha[i] >= 5) {
			char c = i + 'a';
			ret = ret + c;
		}
	}
	if (ret.size() == 0)
		cout << "PREDAJA";
	else
		cout << ret;
	system("pause");
	return 0;
}