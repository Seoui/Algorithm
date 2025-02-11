#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	for (auto& st : skill_trees) {
		bool can = true;
		size_t prev = 0;
		for (int i = 0; i < skill.size(); ++i) {
			size_t cur = st.find(skill[i]);
			if (cur < prev) {
				can = false;
				break;
			}
			prev = cur;
		}
		if (can)
			++answer;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
	system("pause");
	return 0;
}