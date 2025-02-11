#include <iostream>
using namespace std;

bool broken[10];
// ä�� c�� �̵������ϸ� c�� ������ ���� ����, �Ұ����ϸ� 0
int possible(int c) 
{
	if (c == 0){
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (c > 0) {
		// ó���� c�� �����ڸ����� ���峪�� �ش� ä�η� �̵� �Ұ���
		if (broken[c % 10]) return 0;
		len += 1;
		// c�� �����ڸ��� �����ϱ� ���� 10���� ���� ���� ����.
		c /= 10;
	}
	// while���� ����ߴٴ� ���� ä�� c�� ��� ���ڰ� ������ �ȳ�
	// ä�� c�� ������ ���� ����
	return len;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	// ���峭 ��ư �Է�
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	// ������ �ʱⰪ: ���ڹ�ư�� �ȴ��� (+, -)
	int ans = n - 100;
	if (ans < 0)
		ans = -ans;

	// 100������ ä���� �� ����
	for (int i = 0; i <= 1000000; ++i) {
		int c = i;
		// �ش� ä�� c�� �̵��� �� �ִ� ä���ΰ�?
		int len = possible(c);
		// ä�� c�� ���ڹ�ư���� �̵��� �� �ִ� ä���̴�.
		if (len > 0) {
			// ���ڹ�ư���� ä�� c�� �̵��� ��, ��ǥ�ϴ� ä�� n������ �Ÿ�
			int press = c - n;
			if (press < 0)
				press = -press;
			// ���� ans�� ������ �ϴ� Ƚ��. ���� ��ư + press(+,-������ Ƚ��)���� ������
			// �ּڰ� ����
			if (ans > len + press)
				ans = len + press;
		}
	}
	cout << ans << '\n';
	system("pause");
	return 0;
}