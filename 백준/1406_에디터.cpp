#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	list<char> str;
	string s;
	int M;
	cin >> s >> M;
	for (int i = 0; i < s.length(); ++i)
		str.push_back(s[i]);
	list<char>::iterator cursor = end(str);
	while (M--) {
		char a;
		cin >> a;
		if (a == 'P') {
			char b;
			cin >> b;
			str.insert(cursor, b);
		}
		else if(a == 'L'){
			if(cursor != begin(str))
				--cursor;
		}
		else if (a == 'D') {
			if(cursor != end(str))
				++cursor;
		}
		else if (a == 'B') {
			if (cursor != begin(str)) {
				cursor--;
				cursor = str.erase(cursor);
			}
		}
	}
	for (auto& s : str)
		cout << s;
	cout << '\n';
	return 0;
}