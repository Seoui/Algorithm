#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul)
{
	vector<string>::iterator it = find(begin(seoul), end(seoul), "Kim");
	return "김서방은 " + to_string(distance(begin(seoul), it)) + "에 있다";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> s = { "Jane", "Kim" };
	cout << solution(s);
	system("pause");
	return 0;
}