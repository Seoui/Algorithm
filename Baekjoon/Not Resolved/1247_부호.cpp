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

			// ���� ���� ����̰�, �Է��� ����̰�, sum + input�� limit���� Ŀ�߸� �����÷ο���
			if (sum > 0 && input > 0 && sum > LLONG_MAX - input)
				++overflow;
			// ���� ���� �����̰�, �Է��� �����̰�, sum + input�� -limit���� �۾ƾ߸� ����÷ο���
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