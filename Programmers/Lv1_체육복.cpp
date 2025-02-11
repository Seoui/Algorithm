#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	vector<int> student(n + 2, 0);
	for (int i = 0; i < reserve.size(); ++i)
		student[reserve[i]] += 1;
	for (int i = 0; i < lost.size(); ++i) 
		student[lost[i]] -= 1;
	
	for (int i = 1; i < student.size() - 1; ++i) {
		if (student[i] == -1){
			if (student[i - 1] == 1) {
				student[i - 1]--;
				student[i]++;
			}
			else if (student[i + 1] == 1) {
				student[i + 1]--;
				student[i]++;
			}
		}
	}

	for (int i = 1; i < student.size() - 1; ++i)
		if (student[i] >= 0)
			answer++;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	struct exi {
		int n;
		vector<int> lost;
		vector<int> reserve;
	};
	
	exi ex1 = { 5, {2, 4}, {1, 3, 5} };
	exi ex2 = { 5, {2, 4}, {3} };
	exi ex3 = { 3, {3}, {1} };
	
	cout << solution(ex1.n, ex1.lost, ex1.reserve) << endl;
	cout << solution(ex2.n, ex2.lost, ex2.reserve) << endl;
	cout << solution(ex3.n, ex3.lost, ex3.reserve) << endl;
	system("pause");
	return 0;
}