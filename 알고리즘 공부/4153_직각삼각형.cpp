#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num[3];
	while (true) {
		cin >> num[0] >> num[1] >> num[2];
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break;
		sort(num, num + 3);
		if (num[2] * num[2] == num[1] * num[1] + num[0] * num[0])
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return 0;
}