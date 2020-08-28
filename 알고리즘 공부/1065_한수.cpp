#include <iostream>
using namespace std;

int NumHansu(int n)
{
	int ret = 0;
	// n이 100미만인 자연수 일 때
	if (n >= 1 && n < 100)
		return n;

	// n이 100이상인 자연수 일 때, 공차는 최대 4임
	int units = 0;
	int tens = 0;
	int hundreds = 0;
	for (int i = 100; i <= n; ++i)
	{
		units = i % 10;					// 일의 자리 숫자
		tens = i / 10 % 10;				// 십의 자리 숫자
		hundreds = i / 100;				// 백의 자리 숫자

		for (int cd = 0; cd <= 4; ++cd) // cd는 common difference로 공차이다.
			if (((units == tens - cd) && (units == hundreds - 2 * cd)) ||
				((units == tens + cd) && (units == hundreds + 2 * cd)))
				++ret;
	}
	return ret + 99;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; // 최댓값 1000인 자연수
	int ret;
	cin >> N;
	ret = NumHansu(N);
	cout << ret << "\n";

	return 0;
}
