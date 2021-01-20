#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;
	for (int i = 0; i < n; ++i) {
		bitset<32> r = bitset<32>(arr1[i]) | bitset<32>(arr2[i]);
		string sr = r.to_string();
		sr = sr.substr(32 - n, 32);
		for (int i = 0; i < sr.size(); ++i) {
			if (sr[i] == '0')
				sr[i] = ' ';
			else if (sr[i] == '1')
				sr[i] = '#';
		}
		answer.push_back(sr);
	}
	return answer;
}


int main()
{
	solution(6, { 46, 33, 33, 22, 31, 50 }, { 27, 56, 19, 14, 14, 10 });
	return 0;
}