#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
	cout << (a * 60 + b + c) / 60 % 24 << ' ' << (a * 60 + b + c) % 60 << '\n';
    return 0;
}

