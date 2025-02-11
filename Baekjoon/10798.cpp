#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int ml = 0;
	vector<string> v;
	string s;
	for (int i = 0; i < 5; ++i) {
		cin >> s;
		if (ml < s.length())
			ml = s.length();
		v.push_back(s);
	}

	string r;
	for (int i = 0; i < ml; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (v[j].length() <= i) continue;
			r.push_back(v[j][i]);
		}
	}
	cout << r << '\n';
	return 0;
}