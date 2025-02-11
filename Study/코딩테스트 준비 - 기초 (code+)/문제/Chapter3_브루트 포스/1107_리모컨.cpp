#include <iostream>
using namespace std;

bool broken[10];
// 채널 c로 이동가능하면 c의 숫자의 개수 리턴, 불가능하면 0
int possible(int c) 
{
	if (c == 0){
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (c > 0) {
		// 처음엔 c의 일의자리수가 고장나면 해당 채널로 이동 불가능
		if (broken[c % 10]) return 0;
		len += 1;
		// c의 십의자리를 조사하기 위해 10으로 나눈 몫을 구함.
		c /= 10;
	}
	// while문을 통과했다는 것은 채널 c의 모든 숫자가 고장이 안남
	// 채널 c의 숫자의 개수 리턴
	return len;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	// 고장난 버튼 입력
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	// 정답의 초기값: 숫자버튼을 안누름 (+, -)
	int ans = n - 100;
	if (ans < 0)
		ans = -ans;

	// 100만개의 채널을 다 조사
	for (int i = 0; i <= 1000000; ++i) {
		int c = i;
		// 해당 채널 c가 이동할 수 있는 채널인가?
		int len = possible(c);
		// 채널 c는 숫자버튼으로 이동할 수 있는 채널이다.
		if (len > 0) {
			// 숫자버튼으로 채널 c로 이동한 후, 목표하는 채널 n까지의 거리
			int press = c - n;
			if (press < 0)
				press = -press;
			// 현재 ans는 눌러야 하는 횟수. 숫자 버튼 + press(+,-누르는 횟수)보다 작으면
			// 최솟값 갱신
			if (ans > len + press)
				ans = len + press;
		}
	}
	cout << ans << '\n';
	system("pause");
	return 0;
}