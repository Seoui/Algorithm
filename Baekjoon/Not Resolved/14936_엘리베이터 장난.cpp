#include <iostream>
using namespace std;

int dp[100001];
bool state[100000];
int ButtonState(int n, int m)
{
	/*
		���� 1) ��� ��ư�� �� ������.
		���� 2) ¦�� ��ư�� �� ������.
		���� 3) Ȧ�� ��ư�� �� ������.
		���� 4) 1, 4, 7, ... , 3k + 1�� ��ư�� �� ������.
		���� 5) ��� ���� ����
	*/

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof(int) * 100001);
	int N, m; // �������ִ¹�ưN[1, 100000], �־��� �ð�m[1, 100000]
	cin >> N >> m;
	cout << ButtonState(N, m) << '\n';
	system("pause");
	return 0;
}