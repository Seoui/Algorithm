#include <iostream>
#include <vector>
using namespace std;

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
}