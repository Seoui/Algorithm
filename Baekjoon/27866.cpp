#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	int i;
	cin >> S >> i;
	cout << S.at(i - 1) << '\n';
	return 0;
}