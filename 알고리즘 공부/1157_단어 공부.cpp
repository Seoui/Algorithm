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
	// ���ĺ��� ���� Ƚ���� ���ĺ� �迭�� �ִ´�
	for (size_t i = 0; i < word.size(); ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (97 + j == (int)word[i] || 97 + j == (int)word[i] + 32)
				numAlpha[j] += 1;
		}
	}
	// ���ĺ� �迭���� �ִ��� ã�´�
	int max = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (max < numAlpha[i])
			max = numAlpha[i];
	}
	// ���ĺ� �迭���� �ִ��� ������ ���Ҹ� ã�´�
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