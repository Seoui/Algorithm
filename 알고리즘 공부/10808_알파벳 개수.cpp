#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> alpha(26, 0);
	string word;
	cin >> word;
	for (int i = 0; i < word.length(); ++i)
		++alpha[word[i] - 97];
	for (auto& a : alpha)
		cout << a << ' ';
	return 0;
}