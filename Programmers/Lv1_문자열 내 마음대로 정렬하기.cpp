#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) 
{
	vector<string> answer;
	
	for (int i = 0; i < strings.size(); ++i)
		strings[i].insert(begin(strings[i]), strings[i][n]);
	sort(begin(strings), end(strings));
	for (int i = 0; i < strings.size(); ++i)
		strings[i].erase(begin(strings[i]));
	return answer = strings;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<string> s1 = { "sun", "bed", "car" };
	int n1 = 1;
	solution(s1, n1);

	vector<string> s2 = { "abce", "abcd", "cdx" };
	int n2 = 2;
	solution(s2, n1);
	system("pause");
	return 0;
}