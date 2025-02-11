#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
	string num = to_string(x);
	int sum = 0;
	for (int i = 0; i < num.size(); ++i)
		sum += num[i] - '0';

	if (x % sum == 0)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << solution(10) << endl;
	cout << solution(12) << endl;
	cout << solution(11) << endl;
	cout << solution(13) << endl;
	system("pause");
	return 0;
}