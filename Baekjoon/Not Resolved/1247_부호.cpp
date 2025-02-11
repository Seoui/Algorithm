#include <iostream>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 3; ++i) {
		
		int n;
		cin >> n;
		long long sum = 0;
		int overflow = 0;

		for (int j = 0; j < n; ++j) {
			
			long long input;
			cin >> input;

			// 현재 합이 양수이고, 입력이 양수이고, sum + input이 limit보다 커야만 오버플로우임
			if (sum > 0 && input > 0 && sum > LLONG_MAX - input)
				++overflow;
			// 현재 합이 음수이고, 입력이 음수이고, sum + input이 -limit보다 작아야만 언더플로우임
			else if (sum < 0 && input < 0 && sum < LLONG_MIN - input)
				--overflow;

			sum += input;
		}

		if (overflow == 0) {
			if (sum == 0)
				cout << "0";
			else if (sum > 0)
				cout << "+";
			else
				cout << "-";
		}
		else if (overflow > 0)
			cout << "+";
		else
			cout << "-";
		cout << '\n';
	}
	system("pause");
	return 0;
}