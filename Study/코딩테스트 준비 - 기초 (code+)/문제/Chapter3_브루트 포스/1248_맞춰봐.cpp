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
			// 입력은 0인데, 선택한 숫자가 0이 아니면 false
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
	// 전부 통과하면 true
	return true;
}

bool check(int index)
{
	int sum = 0;
	// 현재 위치로부터 뒤로 가면서 sum을 구해야 한다.
	// 여기서 index는 불변이다. 바뀌는건 i.
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

// 총 n개의 수를 찾아야함. 따라서 index가 n개가 되면 종료할꺼임.
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

	/* 두 번째 방법
	// n개의 수를 찾았다. 확인하자.
	if (index == n)
		return ok();

	// 만약 i == j일때 그 값이 0의 값을 갖는다면, 해당 위치는 0만 될 수 있음.
	// i ~ j까지의 합이 0인데, i == j이니까, 결국 s[i] + s[i] == 0 을 만족해야함.
	// 따라서 ans[i] == 0이다.
	if (sign[index][index] == 0) {
		ans[index] = 0;
		// 일단 index위치가 0이면 무조껀 그자리는 0이다.
		// 미련없이 다음 위치부터 조사해서 return하면 된다.
		// return false 할 일 없음.
		return go(index + 1);
	}

	// 위 경우가 아니라면 [-10, -1] 또는 [1, 10] 두 가지 경우임.
	// 두 가지 경우 모두 10개의 경우의 수가 있다.
	for (int i = 1; i <= 10; ++i) {
		// sign[index][index]가 -1이면 ans[index]는 음수가 되어야 함.
		// 그러면 ans[index]는 [-10, -1]까지의 값을 가진다.
		ans[index] = sign[index][index] * i;
		// 다음으로 넘어가자
		if (go(index + 1)) return true;
	}

	return false;
	*/

	/* 첫 번째 방법
	// n개의 수를 찾았다. 확인하자.
	if (index == n)
		return ok();

	// 한 위치에서 가질 수 있는 경우의 수 [-10, 10], 총 21가지 경우가 있다.
	for (int i = -10; i <= 10; ++i) {
		// 그 위치에 다 입력해볼 것이다.
		ans[index] = i;
		// 다음 위치로 넘어간다.
		// 다음 위치에서 false가 나온다면 이 if문은 실행되지 않는다.
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
	// s[cnt]는 0, +, - 값중 하나이다.
	// 이것을 계산하기 편하게 sign배열에 숫자로 입력해놓음.
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