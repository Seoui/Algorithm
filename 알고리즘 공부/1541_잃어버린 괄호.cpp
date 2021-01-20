#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string exp;
	cin >> exp;
	string n;
	bool fo = false;
	int ret = 0;
	for (int i = 0; i <= exp.size(); ++i) {
		if(exp[i] == '+' || exp[i] == '-' || exp[i] == '\0') {
			if (fo == false)
				ret += stoi(n);
			else if (fo == true)
				ret -= stoi(n);

			if (exp[i] == '-')
				fo = true;

			n.clear();
			continue;
		}
		n += exp[i];
	}
	cout << ret;
	system("pause");
	return 0;
}