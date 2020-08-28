#include <iostream>
using namespace std;

int NumHansu(int n)
{
	int ret = 0;
	// n�� 100�̸��� �ڿ��� �� ��
	if (n >= 1 && n < 100)
		return n;

	// n�� 100�̻��� �ڿ��� �� ��, ������ �ִ� 4��
	int units = 0;
	int tens = 0;
	int hundreds = 0;
	for (int i = 100; i <= n; ++i)
	{
		units = i % 10;					// ���� �ڸ� ����
		tens = i / 10 % 10;				// ���� �ڸ� ����
		hundreds = i / 100;				// ���� �ڸ� ����

		for (int cd = 0; cd <= 4; ++cd) // cd�� common difference�� �����̴�.
			if (((units == tens - cd) && (units == hundreds - 2 * cd)) ||
				((units == tens + cd) && (units == hundreds + 2 * cd)))
				++ret;
	}
	return ret + 99;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; // �ִ� 1000�� �ڿ���
	int ret;
	cin >> N;
	ret = NumHansu(N);
	cout << ret << "\n";

	return 0;
}
