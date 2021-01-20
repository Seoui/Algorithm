#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num)
{
	if (num & 1)
		return "Odd";
	else
		return "Even";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	system("pause");
	return 0;
}