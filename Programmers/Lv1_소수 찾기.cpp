#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n)
{
	vector<int> che(n + 1, 0);
	int answer = 0;
	for (int i = 2; i < che.size(); ++i) {
		if (che[i] == 0) {
			for (int j = 2; i * j < che.size(); ++j)
				che[i * j] = 1;
			++answer;
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 10;
	cout << solution(n);
	system("pause");
	return 0;
}