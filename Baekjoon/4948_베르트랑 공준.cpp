#include <iostream>
using namespace std;

bool che[246913];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fill(che, che + 246913, true);
	che[0] = che[1] = false;
	for (int i = 2; i * i <= 246912; ++i) {
		if (che[i])
			for (int j = i * i; j <= 246912; j += i)
				che[j] = false;
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int ret = 0;
		for (int i = n + 1; i <= 2 * n; ++i)
			if (che[i])
				++ret;
		cout << ret << '\n';
	}
	system("pause");
	return 0;
}