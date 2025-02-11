#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int N;
	cin >> N;
	int n = N / 4;
	while (n--) {
		s += "long ";
	}
	s += "int";
	cout << s << '\n';

	return 0;
}