#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2798_∫Ì∑¢¿Ë
void ThreeSums(int N, vector<int>& card, vector<int>& three_sums, vector<int>& picked, int toPick)
{
	if (toPick == 0) {
		three_sums.push_back(picked[0] + picked[1] + picked[2]);
		return;
	}

	int smallest;
	if (picked.empty()) smallest = 0;
	else {
		vector<int>::iterator it = find(begin(card), end(card), picked.back());
		smallest = static_cast<int>(distance(begin(card), it)) + 1;
	}

	for (int next = smallest; next < N; ++next) {
		picked.push_back(card[next]);
		ThreeSums(N, card, three_sums, picked, toPick - 1);
		picked.pop_back();
	}
}

int NearestNumber(int N, int M, vector<int>& _card)
{
	vector<int> picked;
	vector<int> three_sums;
	ThreeSums(N, _card, three_sums, picked, 3);
	int min_difference = 987654321;
	for (auto& card_num : three_sums) {
		if (card_num > M) continue;
		else if (card_num == M) return M;
		min_difference = min(min_difference, M - card_num);
	}
	return M - min_difference;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> card;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int element;
		cin >> element;
		card.push_back(element);
	}
	int result = NearestNumber(N, M, card);
	cout << result << '\n';
	return 0;
}