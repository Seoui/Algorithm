#include <iostream>
#include <vector>
using namespace std;

int A[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// N: ������ ���� ����
	// K: ������ �� ��ġ
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	int num = 0; 
	for (int i = N - 1; i >= 0; i--) {
		int t = K / A[i];
		num += t;
		K -= t * A[i];
	}
	cout << num;
	return 0;
}