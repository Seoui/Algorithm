#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) 
{
	char head = *it;
	++it;
	// 기저 사례: 한 글자로 이루어져 있다면 그냥 그 글자 반환
	if (head == 'b' || head == 'w')
		return string(1, head);
	// 만약 head가 x라면
	string upperLeft = reverse(it);
	// reverse가 호출될 때마다 ++it됨. 
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	// 각각 위와 아래 조각들의 위치를 바꾼다.
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int C;
	cin >> C;
	while (C--) {
		string str;
		cin >> str;
		string::iterator it = begin(str);
		cout << reverse(it) << '\n';
	}
	return 0;
}