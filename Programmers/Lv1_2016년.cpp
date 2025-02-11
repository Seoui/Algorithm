#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// 윤년이면 2월 29일까지
// 5월 24일이면..
// 1월 1일 금요일
// 1월 2일	+1	토요일
//     3	+2	일
//	   4	+3	월
//     5	+4	화
//     6	+5	수
//     7	+6  목
//     8	+7	금
// 1월 31일 +30	
string solution(int a, int b) 
{
	string answer = "";
	vector<string> days = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	vector<pair<int, int>> months = { 
		{1, 31}, {2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
		{7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31} };

	int adays = -1;
	for (int i = 0; i < a - 1; ++i)
		adays += months[i].second;
	adays += b;
	answer = days[adays % 7];
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int a = 1;
	int b = 7;
	
	cout << solution(a, b);
	system("pause");
	return 0;
}