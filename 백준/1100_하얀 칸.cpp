#include <iostream>
#include <string>
using namespace std;

int board[8][8];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int ret = 0;
	string row;
	for (int i = 0; i < 8; ++i) {
		cin >> row;
		if (i % 2 == 0) { // 짝수행이면
			for (int j = 0; j < 8; ++j)
				if (j % 2 == 0 && row[j] == 'F')
					++ret;
		}
		else {
			for (int j = 0; j < 8; ++j)
				if (j % 2 == 1 && row[j] == 'F')
					++ret;
		}
	}
	cout << ret;
	return 0;
}