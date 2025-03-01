#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// num[]의 자릿수 올림을 처리한다.
void normalize(vector<int>& num)
{
	num.push_back(0);
	for (int i = 0; i + 1 < num.size(); ++i) {
		// karatsuba의 곱셈 알고리즘에서 필요한 부분
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		// num[i] >= 0이다. 직관적인 부분.
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	// 숫자의 자릿수가 1보다 크고 현재 최고자리 숫자가 0이라면
	// (vector에 가장 뒤에있는 숫자가 최고자리 숫자임, 앞에서 0넣음)
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

// O(n^2) 곱셈 알고리즘.일반적이다.
// 두 긴 자연수의 곱을 반환한다.
// 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
// a[0]는 1의 자리 숫자. a[max]는 최고자리 숫자. b도 마찬가지
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];

	normalize(c);
	return c;
}

// a+=b*(10^k)를 구현한다.
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	// a가 b보다 크기 때문에 b만 모두 순회하여 a에 더한다.
	int i = 0;
	int ten_k = static_cast<int>(pow(10, k));
	for (auto iter = begin(b); iter != end(b); ++iter)
		a[i++] += *iter * ten_k;
	normalize(a);
}

// a-=b를 구현한다. a>=b를 가정한다.
void subFrom(vector<int>& a, const vector<int>& b)
{
	int i = 0;
	for (auto iter = begin(b); iter != end(b); ++iter)
		a[i++] -= *iter;
	normalize(a);
}

// 두 긴 정수의 곱을 반환한다.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	// 각 수가 몇자리 수인지. 자릿수 길이
	int an = a.size(), bn = b.size();
	// a가 b보다 짧을 경우 둘을 바꾼다. 따라서 앞이 항상 더 크다.
	if (an < bn) return karatsuba(b, a);
	// 기저 사례: a나 b가 비어 있는 경우, 빈 벡터를 반환한다(0이므로).
	if (an == 0 || bn == 0) return vector<int>();
	// 기저 사례: a가 비교적 짧을 경우 O(n^2) 곱셈으로 변경한다.
	if (an <= 50) return multiply(a, b);

	// 다음은 자릿수의 절반이지, 숫자의 절반이 아니다.
	int half = an / 2;
	// a와 b를 밑에서 half자리와 나머지로 분리한다. 
	// a = a_1 * 10^half + a_0
	// b = b_0 * 10^half + b_0
	vector<int> a0(begin(a), begin(a) + half); // 구간에서 뒤 원소는 포함 안함.
	vector<int> a1(begin(a) + half, end(a));
	vector<int> b0(begin(b), begin(b) + min<int>(b.size(), half)); // b가 half자리보다 더 작은 수일 수도 있음.
	vector<int> b1(begin(b) + min<int>(b.size(), half), end(b));

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