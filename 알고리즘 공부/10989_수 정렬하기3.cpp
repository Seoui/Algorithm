#include <iostream>
#include <cstring>
using namespace std;
/*
	counting sort
	�ܼ��ϰ� �������� �����̶�� �ؼ� �����Ѵٰ� �������� ����
	���� ���� ���ں��� �� ������ ������ŭ ����ϸ� �ȴ�.
	��) 2�� 3�� ������ 2�� 3ȸ ���
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int counting[10001];
	memset(counting, 0, sizeof(counting));
	int N, max = 0;
	cin >> N;
	while (N--) {
		short n;
		cin >> n;
		counting[n]++;
		if (n > max) max = n;
	}

	for (short i = 0; i <= max; ++i)
		for (int j = 0; j < counting[i]; ++j)
			cout << i << '\n';
	return 0;
}