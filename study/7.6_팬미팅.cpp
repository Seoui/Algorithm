#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// num[]�� �ڸ��� �ø��� ó���Ѵ�.
void normalize(vector<int>& num)
{
	num.push_back(0);
	for (int i = 0; i + 1 < num.size(); ++i) {
		// karatsuba�� ���� �˰��򿡼� �ʿ��� �κ�
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		// num[i] >= 0�̴�. �������� �κ�.
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	if (num.back() == 0)
		num.pop_back();
	// ������ �ڸ����� 1���� ũ�� ���� �ְ��ڸ� ���ڰ� 0�̶��
	// (vector�� ���� �ڿ��ִ� ���ڰ� �ְ��ڸ� ������, �տ��� 0����)
	/*
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
	*/
}

// O(n^2) ���� �˰���.�Ϲ����̴�.
// �� �� �ڿ����� ���� ��ȯ�Ѵ�.
// �� �迭���� �� ���� �ڸ����� 1�� �ڸ��������� ������ ����Ǿ� �ִ�.
// a[0]�� 1�� �ڸ� ����. a[max]�� �ְ��ڸ� ����. b�� ��������
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() - 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];

	normalize(c);
	return c;
}

// a+=b*(10^k)�� �����Ѵ�.
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	// a�� b���� ũ�� ������ b�� ��� ��ȸ�Ͽ� a�� ���Ѵ�.
	int i = 0;
	int ten_k = static_cast<int>(pow(10, k));
	for (auto iter = begin(b); iter != end(b); ++iter)
		a[i++] += *iter * ten_k;
	//normalize(a);
}

// a-=b�� �����Ѵ�. a>=b�� �����Ѵ�.
void subFrom(vector<int>& a, const vector<int>& b)
{
	int i = 0;
	for (auto iter = begin(b); iter != end(b); ++iter)
		a[i++] -= *iter;
	//normalize(a);
}

void add(vector<int>& vec1, vector<int>& vec2, int k)
{
	int s = max(vec2.size() + k, vec1.size());

	vec1.resize(s, 0);
	vec2.resize(s, 0);

	for (int i = 0; i < s - k; i++)
	{
		vec1[i + k] += vec2[i];
	}
}

void sub(vector<int>& vec1, vector<int>& vec2)
{
	int s = max(vec1.size(), vec2.size());

	vec1.resize(s, 0);
	vec2.resize(s, 0);
	for (int i = 0; i < s; i++) vec1[i] -= vec2[i];
}

// �� �� ������ ���� ��ȯ�Ѵ�.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	// �� ���� ���ڸ� ������. �ڸ��� ����
	int an = (int)a.size(), bn = (int)b.size();
	// a�� b���� ª�� ��� ���� �ٲ۴�. ���� ���� �׻� �� ũ��.
	if (an < bn) return karatsuba(b, a);
	// ���� ���: a�� b�� ��� �ִ� ���, �� ���͸� ��ȯ�Ѵ�(0�̹Ƿ�).
	if (an == 0 || bn == 0) return vector<int>();
	// ���� ���: a�� ���� ª�� ��� O(n^2) �������� �����Ѵ�.
	if (an <= 50) return multiply(a, b);

	// ������ �ڸ����� ��������, ������ ������ �ƴϴ�.
	int half = an / 2;
	// a�� b�� �ؿ��� half�ڸ��� �������� �и��Ѵ�. 
	// a = a_1 * 10^half + a_0
	// b = b_0 * 10^half + b_0
	vector<int> a0(begin(a), begin(a) + half); // �������� �� ���Ҵ� ���� ����.
	vector<int> a1(begin(a) + half, end(a));
	vector<int> b0(begin(b), begin(b) + min<int>((int)b.size(), half)); // b�� half�ڸ����� �� ���� ���� ���� ����.
	vector<int> b1(begin(b) + min<int>((int)b.size(), half), end(b));

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0); subFrom(z1, z2);
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int Hugs(const string& m, const string& f)
{
	int N = (int)m.size(), M = (int)f.size();
	vector<int> A(N), B(M);
	// ���ڴ� 1, ���ڴ� 0
	for (int i = 0; i < N; ++i) A[i] = (m[i] == 'M');
	for (int i = 0; i < M; ++i) B[M-i-1] = (f[i] == 'M');
	// karatsuba �˰��򿡼� �ڸ� �ø��� �����Ѵ�.
	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	// �־��� member�� fan�� ���ÿ� �����ϴ� ������ �� ������ �������� ������ ��,
	// member�� ������ ����϶� ���� fan�� ������ ����϶� ���� ���ÿ� �����ϰ� �ȴ�.
	for (int i = N - 1; i < M; ++i)
		if (C[i] == 0)
			++allHugs;
	return allHugs;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<int> a = { 1, 2, 3, 4 };
	vector<int> b = { 5, 6, 7 };
	vector<int> c(a);
	vector<int> d(b);
	addTo(a, b, 0);
	add(c, d, 0);
	/*
	subFrom(a, b);
	sub(c, d);*/
	int asd = 5;
	/*
	int C;
	cin >> C;
	while (C--) {
		string member;
		string fan;
		cin >> member >> fan;
		cout << Hugs(member, fan) << '\n';
	}
	*/
	system("pause");
	return 0;
}