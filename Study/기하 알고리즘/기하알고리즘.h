#pragma once
#include <iostream>
using namespace std;

const double PI = 2.0 * acos(0.0);

struct vector2
{
	double x, y;

	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	bool operator==(const vector2& rhs) const
	{
		return x == rhs.x && rhs.y == rhs.y;
	}
	// < ������ ���� x��ǥ���� ũ�⸦ ����.
	// x��ǥ�� ������ y��ǥ���� ũ�⸦ ����.
	bool operator<(const vector2& rhs) const 
	{
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	vector2 operator+(const vector2& rhs) const
	{
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator-(const vector2& rhs) const
	{
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator*(double rhs) const
	{
		return vector2(x * rhs, y * rhs);
	}
	// ������ ����
	double norm() const 
	{ 
		// #include <cmath>
		// hypot �Լ��� side1 �� side2 �� ���� ���̸� ������� �����ﰢ���� ������ ���̸� ����Ѵ�.
		// ���������� ��Ÿ����� ������ ���(sqrt�Լ� ���)
		return hypot(x, y); 
	}
	// ���� ����
	vector2 normalize() const
	{
		return vector2(x / norm(), y / norm());
	}
	// x���� ���� �������κ��� �� ���ͱ��� �ݽð� �������� �� ����
	// ���� ȣ������
	double polar() const 
	{ 
		// #include <cmath>
		// fmod(x, y): x/y�� �ε� �Ҽ��� �������� ������.
		// atan2�� �� ������ ������ x���� �����̴ϱ�.
		// atan2�� ����� ���̴�. �� ���� ������ [-pi, pi]�ε�,
		// ������ [0, 2pi)�� �ٲٱ� ���ؼ� ����� ���� ���� 2pi�� ����. �׷��� �ѹ��� �� ���̰� ������ 2pi�ؼ� ������ �������°� 
		// ���� ��ȯ ���� ��.
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
	double dot(const vector2& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}
	// ���⼭�� ������ ���� �������� �� �ٸ���, ������ ���̸� ��ȯ�Ѵ�.
	double cross(const vector2& rhs) const
	{
		return x * rhs.y - rhs.x * y;
	}
	// �� ���͸� rhs�� �翵�� ����
	vector2 project(const vector2& rhs) const
	{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

// b���������� p�������� �Ÿ� - a���������� p�������� �Ÿ�
// a�� b���� p�� �󸶳� �� ������� ��ȯ�ϴ� �Լ�
double howMuchCloser(vector2 p, vector2 a, vector2 b)
{
	return (b - p).norm() - (a - p).norm();
}

// �������� ���� b�� ���� a�� �ݽð� �����̸� ���, �ð� �����̸� ����, �����̸� 0�� ��ȯ
double ccw(vector2 a, vector2 b)
{
	return a.cross(b);
}

// p�� �������� ���� b�� ���� a�� �ݽð� �����̸� ���, �ð� �����̸� ����, �����̸� 0�� ��ȯ
double ccw(vector2 p, vector2 a, vector2 b)
{
	return ccw(a - p, b - p);
}

/*	���� ���� �˻� �˰���
*	(a, b)�� �����ϴ� ������ (c, d)�� �����ϴ� ������ ������ x�� ��ȯ
*	�� ���� �����̸� (��ġ�� ��츦 ����) ������, �ƴϸ� ���� ��ȯ
*	������ �������� ���� ���� ������ �� ���� ���⺤�ͷμ� ǥ���Ѵ�.
*	���⼭ a, b, c, d�� ���� '��ǥ' �� '��ġ����'��� ���� �ָ� */
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x)
{
	// ���� ab�� �������� ���� cd�� ��� ���⿡ ��ġ�� �ִ��� (�ð�����̸� ����, �ݽð�����̸� ���)
	double det = (b - a).cross(d - c);
	// ���� �� ������ ������ ���밪�� 0�� ������ �����ϴٸ� ���� -> false
	if (fabs(det) < DBL_EPSILON) return false;
	// ������ �����Ŀ� �����Ͽ� ������ ��ǥ�� ����
	x = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

/*	���� ���� �˻� �˰���
*	�� ���� ���� �� ������ ���� ��, ���е��� ���� �� ����
*	1. �� ������ ���� ��ġ�� ����
*	2. �� ������ �� ������ ����
*	3. �� ������ ������
*	4. �� ������ �ٸ� ���� �ȿ� ���Ե� 
*/

// (a, b)�� (c, d)�� ������ �� ������ �� �̵��� �� ������ ��ġ���� Ȯ���Ѵ�. �������� ��ȯ��.
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p)
{
	// �� ������ �����ϴ� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// ���� a�� b���� ��, �����ʿ� �ִٸ�, ����
	if (b < a) swap(a, b);
	// ���� c�� d���� ��, �����ʿ� �ִٸ�, ����
	if (d < c) swap(c, d);
	// ccw�� 0�̸� ������
	// ���⼭ if ���ǹ��� true�� �Ǿ� return false�� �Ƿ���, ccw != 0�̾�� ��. ��, �� ������ ���� �ʰų�,
	// cd������ ab���� �����ʿ� �־� �Ȱ�ġ�ų�, ab������ cd���� �����ʿ� �־� �Ȱ�ġ�� �ٷ� false
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;
	// ���� �Ʒ��� ���๮�� �����´ٴ� ���� (ccw(a, b, c) == 0 && b >= c && d >= a)�̴�.
	// ��ġ�� ����. �������� ū ���� ���̴�...
	if (a < c)
		p = c;
	else p = a;
	return true;
}

// p�� (a, b)�� ���θ鼭 �� ���� x, y�࿡ ������ �ּ� �簢�� ���ο� �ִ��� Ȯ���Ѵ�.
// a, b, p�� ������ �� �ִٰ� �����Ѵ�.
// b�� ������ ���, a�� ���� �ϴ� ���� ���簢�� ����� ����ض�. p�� ���簢���� �밢���� ���� ab�� ���� ���� ���� ���� �ִ�.
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
{
	if (b < a) swap(a, b);
	// p�� a���̰ų� b���̸� ���簢�� ���ο� �ִ�, �Ǵ� p�� a�� ���ܿ� �����鼭 p�� b�� ���ϴܿ� ������ �밢���� ��ġ�Ѵٴ� �ǹ̴�.
	return p == a || p == b || (a < p&& p < b);
}

// (a, b)���а� (c, d)������ ������ p�� ��ȯ�Ѵ�.
// ������ ���� ���� ��� �ƹ� ���̳� ��ȯ�Ѵ�.
// �� ������ �������� ���� ��� false�� ��ȯ�Ѵ�.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p)
{
	// �� ������ ������ ��츦 �켱 ���ܷ� ó���Ѵ�.
	// lineIntersection�Լ��� �� ������ ���Ⱑ �޶� ��ġ�� ��� true�̴�.
	// ���� �� ������ �����ϰų� ��ġ�� ��� false��. false�� ��� parallelSegments ȣ��
	if (!lineIntersection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);
	// p�� �� ���п� ���ԵǾ� �ִ� ��쿡�� ���� ��ȯ�Ѵ�.
	// p�� �̹� ���� lineIntersection���� ����. �� ������ p�� ���� ab�ȿ� �ְ�, ���� cd �ȿ� �־�߸� true, �ƴϸ� false
	return inBoundingRectangle(p, a, b) &&
		inBoundingRectangle(p, c, d);
}

// �������� �ʿ���� ���� ���� �˻縸 �����ϴ� �˰���
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d)
{
	// ccw(a, b, c)�� ����ab�� �������� ����ac�� �ð���⿡ ������ ����, �ݽð���⿡ ������ ���
	// �� ������ �����ϴ� ����� ab, cd�� �Ѵ� ����������.
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	// ab�� 0�� ���� �� ���� ��찡 �ִ�.
	// 1. ccw(a, b, c), ccw(a, b, d) ��� 0�� ��� => cd�� ab�� ���� ������ �ְų�, ������ ��ġ�� ����
	// (������ ��ġ�� ��쿡�� �� ������ ���Ⱑ ���Ƶ� �ǰ� �޶� �ȴ�)
	// 2. ccw(a, b, c)�� ccw(a, b, d) �� �� �ϳ��� 0�� ��� 
	//		=> 0�� ���� ���� ���� ab�� ���� ������ �ִ�. 
	//		���� ccw(a, b, c) == 0�̶�� �� c�� ab�� ���� ������ �ִ�. 
	//		�� d�� ab�� �ٸ� ������ �ִ�.
	//		���� �̷� ��� cd�� 0�� �ƴϰ� ��.
	// �� ������ �� ���� ���� �ְų� ������ ��ġ�� ���
	if (ab == 0 && cd == 0) {
		// ��� ���Ǽ��� ���� �� �����ְ�
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		// b < c(�Ǵ� d < a)�̸� �� ������ ������ �����ϱ� ! �ٿ��� false ��ȯ. ���� (b >= c && d >= a)�̸� true ��ȯ��. 
		return !(b < c || d < a);
	}
	// ����Ƶ� �� ������ �� �������� ���� ������, ab�� cd�� �� �� �������߸�(�Ǵ� �ϳ��� �����̰�, �ϳ��� 0�� ����) true.
	return ab <= 0 && cd <= 0;
}

// �� p���� (a, b) ������ ���� ������ ���� ���Ѵ�.
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b)
{
	return a + (p - a).project(b - a);
}

// �� p�� (a, b) ���� ������ �Ÿ��� ���Ѵ�.
double pointToLine(vector2 p, vector2 a, vector2 b)
{
	return (p - perpendicularFoot(p, a, b)).norm();
}