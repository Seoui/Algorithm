#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 서의
	/*
	int a = 0, b = 0, c = 0;
	int e, s, m, ret = 0;
	cin >> e >> s >> m;
	while (true) {
		++ret;
		++a, ++b, ++c;
		if (a == 16) a = 1;
		if (b == 29) b = 1;
		if (c == 20) c = 1;

		if (a == e && b == s && c == m){
			cout << ret;
			system("pause");
			return 0;
		}
	}*/
	
	// 백준 - 1
	/*
	int E, S, M;
	cin >> E >> S >> M;
	int e = 1, s = 1, m = 1;
	for (int i = 1;; ++i) {
		if (e == E && s == S && m == M) {
			cout << i << '\n';
			break;
		}
		e += 1;
		s += 1;
		m += 1;
		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}
	return 0;*/

	// 백준 - 2
	/*
	int e, s, m;
	cin >> e >> s >> m;
	e -= 1;
	s -= 1;
	m -= 1;
	for (int i = 0;; ++i) {
		if (i % 15 == e && i % 28 == s && i % 19 == m) {
			cout << i + 1 << '\n';
			break;
		}
	}*/

	// 백준 - 3
	int e, s, m;
	cin >> e >> s >> m;
	cout << (6916 * e + 4845 * s + 4200 * m - 1) % (15 * 28 * 19) + 1 << '\n';
	return 0;
}