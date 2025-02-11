#include <iostream>
using namespace std;

const int MAX = 1000000;
int prime[MAX];
int pn;
bool check[MAX + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 2; i <= MAX; ++i) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i + i; j <= MAX; j += i)
				check[j] = true;
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i < pn; ++i) {
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}

	return 0;
}

/*
bool che[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill(che, che + 10001, true);
	che[0] = che[1] = false;
	for (int i = 2; i * i <= 10000; ++i) 
		if (che[i])
			for (int j = i * i; j <= 10000; j += i)
				che[j] = false;
	
	int T; 
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = n / 2; i >= 2; --i) {
			if (che[i] && che[n - i]) {
				cout << i << ' ' << n - i << '\n';
				break;
			}
		}
	}
	system("pause");
	return 0;
}*/