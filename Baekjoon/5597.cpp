#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a;
	vector<int> vec(30, 0);
	for(int i = 0; i < 28; ++i) {
		cin >> a;
		vec[a - 1] = a;
	}

	for (int i = 0; i < 30; ++i) {
		if (vec[i] == 0)
			cout << i + 1 << '\n';
	}
	return 0;
}