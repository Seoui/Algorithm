#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int num)
{
	long long n = num;
	int answer = 0;
	bool s = false;
	for(int i = 0; i < 500; ++i) {
		if (n == 1) {
			s = true;
			break;
		}
		if (n & 1)// È¦¼ö¶ó¸é
			n = n * 3 + 1;
		else // Â¦¼ö¶ó¸é
			n = n / 2;
		answer++;
	}
	if (s == false)
		answer = -1;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << solution(626331);
	system("pause");
	return 0;
}