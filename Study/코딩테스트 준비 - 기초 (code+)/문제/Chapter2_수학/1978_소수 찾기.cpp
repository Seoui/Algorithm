#include <iostream>
#include <vector>
using namespace std;

// น้มุ
bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i*i <= x; ++i)
		if (x % i == 0)
			return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (is_prime(num))
			cnt += 1;
	}
	cout << cnt << '\n';
	return 0;
}


/*
void CreatePrimeTable(vector<int>& primeTable)
{
	primeTable[0] = -1;
	primeTable[1] = -1;
	for (int num = 2; num < 1001; ++num)
	{
		for (int div = 2; div < num; ++div) {
			if (num % div == 0)
				primeTable[num] = -1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> primeTable(1001, 0);
	CreatePrimeTable(primeTable);
	vector<int> num;
	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	int count = 0;
	for (auto& n : num)
		if (primeTable[n] == 0)
			count++;
	cout << count << '\n';
	return 0;
}*/