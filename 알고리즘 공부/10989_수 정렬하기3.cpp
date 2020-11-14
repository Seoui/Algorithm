#include <iostream>
#include <cstring>
using namespace std;
/*
	counting sort
	단순하게 생각하자 정렬이라고 해서 정렬한다고 생각하지 말고
	그저 작은 숫자부터 그 숫자의 개수만큼 출력하면 된다.
	예) 2가 3개 있으면 2를 3회 출력
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