#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int sign[10][10];
int ans[10];

bool ok()
{
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += ans[j];
			// �Է��� 0�ε�, ������ ���ڰ� 0�� �ƴϸ� false
			if (sign[i][j] == 0) {
				if (sum != 0) 
					return false;
			}
			else if (sign[i][j] > 0) {
				if (sum <= 0)
					return false;
			}
			else if (sign[i][j] < 0) {
				if (sum >= 0)
					return false;
			}
		}
	}
	// ���� ����ϸ� true
	return true;
}

bool check(int index)
{
	int sum = 0;
	// ���� ��ġ�κ��� �ڷ� ���鼭 sum�� ���ؾ� �Ѵ�.
	// ���⼭ index�� �Һ��̴�. �ٲ�°� i.
	for (int i = index; i >= 0; --i) {
		sum += ans[i];
		if (sign[i][index] == 0) {
			if (sum != 0) return false;
		}
		else if (sign[i][index] < 0){
			if (sum >= 0) return false;
		}
		else if (sign[i][index] > 0) {
			if (sum <= 0) return false;
		}
	}
	return true;
}

// �� n���� ���� ã�ƾ���. ���� index�� n���� �Ǹ� �����Ҳ���.
bool go(int index)
{
	if (index == n) return true;

	if (sign[index][index] == 0) {
		ans[index] = 0;
		return check(index) && go(index + 1);
	}

	for (int i = 1; i <= 10; ++i) {
		ans[index] = sign[index][index] * i;
		if (check(index) && go(index + 1)) return true;
	}
	return false;

	/* �� ��° ���
	// n���� ���� ã�Ҵ�. Ȯ������.
	if (index == n)
		return ok();

	// ���� i == j�϶� �� ���� 0�� ���� ���´ٸ�, �ش� ��ġ�� 0�� �� �� ����.
	// i ~ j������ ���� 0�ε�, i == j�̴ϱ�, �ᱹ s[i] + s[i] == 0 �� �����ؾ���.
	// ���� ans[i] == 0�̴�.
	if (sign[index][index] == 0) {
		ans[index] = 0;
		// �ϴ� index��ġ�� 0�̸� ������ ���ڸ��� 0�̴�.
		// �̷þ��� ���� ��ġ���� �����ؼ� return�ϸ� �ȴ�.
		// return false �� �� ����.
		return go(index + 1);
	}

	// �� ��찡 �ƴ϶�� [-10, -1] �Ǵ� [1, 10] �� ���� �����.
	// �� ���� ��� ��� 10���� ����� ���� �ִ�.
	for (int i = 1; i <= 10; ++i) {
		// sign[index][index]�� -1�̸� ans[index]�� ������ �Ǿ�� ��.
		// �׷��� ans[index]�� [-10, -1]������ ���� ������.
		ans[index] = sign[index][index] * i;
		// �������� �Ѿ��
		if (go(index + 1)) return true;
	}

	return false;
	*/

	/* ù ��° ���
	// n���� ���� ã�Ҵ�. Ȯ������.
	if (index == n)
		return ok();

	// �� ��ġ���� ���� �� �ִ� ����� �� [-10, 10], �� 21���� ��찡 �ִ�.
	for (int i = -10; i <= 10; ++i) {
		// �� ��ġ�� �� �Է��غ� ���̴�.
		ans[index] = i;
		// ���� ��ġ�� �Ѿ��.
		// ���� ��ġ���� false�� ���´ٸ� �� if���� ������� �ʴ´�.
		if (go(index + 1)) return true;
	}

	return false;*/
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> s;
	int cnt = 0;
	// s[cnt]�� 0, +, - ���� �ϳ��̴�.
	// �̰��� ����ϱ� ���ϰ� sign�迭�� ���ڷ� �Է��س���.
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (s[cnt] == '0')
				sign[i][j] = 0;
			else if (s[cnt] == '+')
				sign[i][j] = 1;
			else
				sign[i][j] = -1;
			cnt += 1;
		}
	}
	
	go(0);
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	system("pause");
	return 0;
}