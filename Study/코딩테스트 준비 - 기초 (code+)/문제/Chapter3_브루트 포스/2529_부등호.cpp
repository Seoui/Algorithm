#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char a[20];
vector<string> ans;
bool check[10];

bool good(char x, char y, char op)
{
	if (op == '<') {
		if (x > y) 
			return false;
	}
	if (op == '>') {
		if (x < y)
			return false;
	}
	return true;
}

//index : 부등호 배열의 인덱스 
void go(int index, string num)
{
	if (index == k + 1) {
		ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		if (check[i]) continue;
		if (index == 0 || good(num[index - 1], i + '0', a[index - 1])) {
			check[i] = true;
			go(index + 1, num + to_string(i));
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> a[i];
	go(0, string{});
	auto p = minmax_element(begin(ans), end(ans));
	cout << *p.second << '\n';
	cout << *p.first << '\n';
	system("pause");
	return 0;
}