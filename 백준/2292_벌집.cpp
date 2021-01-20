#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int input;
	cin >> input;
	if (input == 1) {
		cout << input << endl;
		return 0;
	}
	int c = (input - 2) / 3;
	int result = (1 + static_cast<int>(sqrt(1 + 4 * c))) / 2 + 1;
	cout << result << endl;
	return 0;
}
