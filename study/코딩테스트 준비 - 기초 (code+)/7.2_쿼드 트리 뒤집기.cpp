#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) 
{
	char head = *it;
	++it;
	// ���� ���: �� ���ڷ� �̷���� �ִٸ� �׳� �� ���� ��ȯ
	if (head == 'b' || head == 'w')
		return string(1, head);
	// ���� head�� x���
	string upperLeft = reverse(it);
	// reverse�� ȣ��� ������ ++it��. 
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	// ���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�.
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