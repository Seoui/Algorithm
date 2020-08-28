#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	cin >> word;

	for (int i = 0; i < 26; ++i)
	{
		bool bHave = false;
		for (size_t j = 0; j < word.size(); ++j)
		{
			if (97 + i == word[j])
			{
				cout << to_string(j) + " ";
				bHave = true;
				break;
			}
		}
		if (!bHave)
			cout << "-1 ";
	}
	return 0;
}