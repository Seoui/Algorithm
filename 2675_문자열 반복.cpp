#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	int repeatNum = 0;
	string str = "";

	cin >> testCase;
	while (testCase--)
	{
		cin >> repeatNum >> str;
		for (size_t i = 0; i < str.size(); ++i)
			for (int j = 0; j < repeatNum; ++j)
				cout << str[i];
		cout << "\n";
	}
	return 0;
}