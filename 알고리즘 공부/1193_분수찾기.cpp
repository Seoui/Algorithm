#include <iostream>
using namespace std;

int sumTable[4473];

int sigma(int n)
{
	return n * (n + 1) / 2;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	/*
	int X, i;
	cin >> X;
	for (i = 1; i < X; ++i)
		X -= i;

	if (i % 2)
		cout << i - X + 1 << '/' << X;
	else
		cout << X << '/' << i - X + 1;
		*/
	
	for (int i = 1; i <= 4472; ++i)
		sumTable[i] = sigma(i);

	int X;
	cin >> X;
	for (int i = 1; i <= 4472; ++i) {
		if (sumTable[i] >= X) {
			if (i % 2 == 0) {// 짝수행이라면
				int de = 1;
				int nu = i;
				for (int j = sumTable[i]; j > X; --j) {
					de++;
					nu--;
				}
				cout << nu << '/' << de;
				break;
			}
			else {// 홀수행이라면
				int de = i;
				int nu = 1;
				for (int j = sumTable[i]; j > X; --j) {
					de--;
					nu++;
				}
				cout << nu << '/' << de;
				break;
			}

		}
	}
	return 0;
}