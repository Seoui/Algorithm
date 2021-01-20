#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	int a, b, c;
	int result;
	int count = 0;
	char num = 0b0110000; //아스키 코드 '0'
	cin >> a >> b >> c;
	result = a * b * c;
	str = to_string(result);

	for (int j = 0; j < 10; ++j)
	{
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (num == str[i])
				count++;
		}
		cout << count << '\n';
		num += 0b0000001; // 아스키 코드 1씩 증가 => 문자열 한개씩 증가
		count = 0;
	}

	return 0;
}