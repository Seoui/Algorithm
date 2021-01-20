#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	if (m + T > M) {
		cout << -1;
		return 0;
	}
	int Atime = 0;
	int Etime = 0;
	int curM = m;
	while (Etime != N) {
		if (curM + T <= M) {
			curM = curM + T;
			Atime++; Etime++;
		}
		else {// ½¯ ¶§
			curM = curM - R;
			if (curM < m) curM = m;
			Atime++;
		}
	}
	cout << Atime;
	system("pause");
	return 0;
}
/*#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	if (m + T > M) {
		cout << -1;
		return 0;
	}
	int AM = m + N * T;
	int time = 0;
	while (AM > M) {
		AM -= R;
		if (AM < m) AM = m;
		time++;
	}
	cout << time + N;
	system("pause");
	return 0;
}*/