#include <iostream>
#include <string>
using namespace std;

int N, M;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> S;

	int ret = 0;
	for (int i = 1; i < S.size(); ++i) {
		int c = 0;
		if (S[i - 1] == 'I') {
			while (S[i] == 'O' && S[i + 1] == 'I') {
				i += 2;
				++c;
				if (c == N) {
					--c;
					ret++;
				}
			}
		}
	}
	cout << ret;
	return 0;
}