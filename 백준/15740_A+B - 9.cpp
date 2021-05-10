#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string operator+(string a, string b)
{
	bool na = false;
	bool nb = false;
	string ret;

	if (a[0] == '-') {
		a.erase(begin(a));
		if (a[0] == '0')
			na = false;
		else
			na = true;
	}
	if (b[0] == '-') {
		b.erase(begin(b));
		if (b[0] == '0')
			na = false;
		else
			nb = true;
	}

	reverse(begin(a), end(a));
	reverse(begin(b), end(b));

	while (a.size() > b.size())
		b += '0';
	while (a.size() < b.size())
		a += '0';

	int altb = -1;	// a > b�̸� 1, a < b�̸� 0, a == b�̸� -1
	for (int i = int(a.size()) - 1 ; i >= 0; --i) {
		if (a[i] > b[i]) {
			altb = 1;
			break;
		}
		else if (a[i] < b[i]) {
			altb = 0;
			break;
		}
	}

	if((na && !nb) || (!na && nb)) {	// �� ���� �ϳ��� �������
		if (altb == 1) {// ���� b�� �� �۴ٸ�
			for (int i = 0; i < b.size(); ++i)	// �� �ڸ��� 9�� ����
				b[i] = '9' - b[i] + '0';
			reverse(begin(b), end(b));
			b = b + string("1");
			reverse(begin(b), end(b));

			if (b.size() > a.size())
				b.erase(end(b) - 1);

			int carry = 0;
			for (int i = 0; i < b.size(); ++i) {
				int s = (a[i] - '0') + (b[i] - '0');
				ret += (s + carry) % 10 + '0';
				carry = (s + carry) / 10;
			}
			
			reverse(begin(ret), end(ret));
			if (na)
				ret.insert(begin(ret), '-');
		}
		else if (altb == 0) {// ���� a�� �� �۴ٸ�
			for (int i = 0; i < a.size(); ++i)	// �� �ڸ��� 9�� ����
				a[i] = '9' - a[i] + '0';
			reverse(begin(a), end(a));
			a = a + string("1");
			reverse(begin(a), end(a));

			if (a.size() > b.size())
				a.erase(end(a) - 1);

			int carry = 0;
			for (int i = 0; i < a.size(); ++i) {
				int s = (a[i] - '0') + (b[i] - '0');
				ret += (s + carry) % 10 + '0';
				carry = (s + carry) / 10;
			}

			reverse(begin(ret), end(ret));
			if (nb)
				ret.insert(begin(ret), '-');
		}
		else if (altb == -1) // �� ���� ������ ���ٸ�
			ret = "0";
	}
	else {	// �� ���� ��ȣ�� ���ٸ�
		int carry = 0;
		for (int i = 0; i < a.size(); ++i) {
			int s = (a[i] - '0') + (b[i] - '0');
			ret += (s + carry) % 10 + '0';
			carry = (s + carry) / 10;
		}

		if (carry != 0)
			ret += carry + '0';

		reverse(begin(ret), end(ret));
		if ((na && nb) && altb != -1)
			ret.insert(begin(ret), '-');
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a, b;
	cin >> a >> b;
	string ret = a + b;
	char buho = ' ';
	for (int i = 0; i < ret.size(); ++i) {
		if (ret[i] == '-') {
			buho = '-';
			continue;
		}
		if (ret[i] != '0'){
			ret = ret.substr(i, ret.size() - i);
			break;
		}
	}
	if(buho == '-')
		ret.insert(begin(ret), buho);
	cout << ret << endl;
	return 0;
}