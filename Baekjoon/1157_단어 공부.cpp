#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numAlpha[26] = { 0, };
	string word;
	cin >> word;
	// 알파벳이 나온 횟수를 알파벳 배열에 넣는다
	for (size_t i = 0; i < word.size(); ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (97 + j == (int)word[i] || 97 + j == (int)word[i] + 32)
				numAlpha[j] += 1;
		}
	}
	// 알파벳 배열에서 최댓값을 찾는다
	int max = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (max < numAlpha[i])
			max = numAlpha[i];
	}
	// 알파벳 배열에서 최댓값을 가지는 원소를 찾는다
	int maxIndex = 0;
	int numMax = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (max == numAlpha[i])
		{
			maxIndex = i;
			++numMax;
		}
	}
	if (numMax > 1)
		cout << "?" << "\n";
	else
		cout << (char)(maxIndex + 65) << "\n";
	return 0;
}