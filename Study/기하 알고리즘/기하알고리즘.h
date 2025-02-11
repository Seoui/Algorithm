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
	// < 연산은 먼저 x좌표끼리 크기를 비교함.
	// x좌표가 같으면 y좌표끼지 크기를 비교함.
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
	// 벡터의 길이
	double norm() const 
	{ 
		// #include <cmath>
		// hypot 함수는 side1 및 side2 두 변의 길이를 기반으로 직각삼각형의 빗변의 길이를 계산한다.
		// 내부적으로 피타고라스의 정리를 사용(sqrt함수 사용)
		return hypot(x, y); 
	}
	// 단위 벡터
	vector2 normalize() const
	{
		return vector2(x / norm(), y / norm());
	}
	// x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
	// 각은 호도법임
	double polar() const 
	{ 
		// #include <cmath>
		// fmod(x, y): x/y의 부동 소수점 나머지를 리턴함.
		// atan2를 쓴 이유는 어차피 x축이 기준이니까.
		// atan2의 결과는 각이다. 이 각의 범위는 [-pi, pi]인데,
		// 범위를 [0, 2pi)로 바꾸기 위해서 결과로 나온 각에 2pi를 더함. 그러면 한바퀴 돈 셈이고 나누기 2pi해서 나누어 떨어지는게 
		// 최종 반환 값이 됨.
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
	double dot(const vector2& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}
	// 여기서의 외적은 실제 외적과는 좀 다르고, 외적의 길이를 반환한다.
	double cross(const vector2& rhs) const
	{
		return x * rhs.y - rhs.x * y;
	}
	// 이 벡터를 rhs에 사영한 벡터
	vector2 project(const vector2& rhs) const
	{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

// b점에서부터 p점까지의 거리 - a점에서부터 p점까지의 거리
// a가 b보다 p에 얼마나 더 가까운지 반환하는 함수
double howMuchCloser(vector2 p, vector2 a, vector2 b)
{
	return (b - p).norm() - (a - p).norm();
}

// 원점에서 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0을 반환
double ccw(vector2 a, vector2 b)
{
	return a.cross(b);
}

// p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0을 반환
double ccw(vector2 p, vector2 a, vector2 b)
{
	return ccw(a - p, b - p);
}

/*	직선 교차 검사 알고리즘
*	(a, b)를 포함하는 직선과 (c, d)를 포함하는 직선의 교점을 x에 반환
*	두 선이 평행이면 (겹치는 경우를 포함) 거짓을, 아니면 참을 반환
*	직선의 방정식을 직선 위에 임의의 한 점과 방향벡터로서 표현한다.
*	여기서 a, b, c, d는 점의 '좌표' 즉 '위치벡터'라는 점을 주목 */
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x)
{
	// 직선 ab를 기준으로 직선 cd가 어느 방향에 위치해 있는지 (시계방향이면 음수, 반시계방향이면 양수)
	double det = (b - a).cross(d - c);
	// 만약 두 벡터의 외적의 절대값이 0에 무한히 근접하다면 평행 -> false
	if (fabs(det) < DBL_EPSILON) return false;
	// 직선의 방정식에 대입하여 교차점 좌표를 구함
	x = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

/*	선분 교차 검사 알고리즘
*	한 직선 위에 두 선분이 있을 때, 선분들의 관계 네 가지
*	1. 두 선분이 서로 겹치지 않음
*	2. 두 선분이 한 점에서 닿음
*	3. 두 선분이 겹쳐짐
*	4. 한 선분이 다른 선분 안에 포함됨 
*/

// (a, b)와 (c, d)가 평행한 두 선분일 때 이들이 한 점에서 겹치는지 확인한다. 교차점도 반환함.
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p)
{
	// 두 선분은 평행하다 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// 만약 a가 b보다 위, 오른쪽에 있다면, 스왑
	if (b < a) swap(a, b);
	// 만약 c가 d보다 위, 오른쪽에 있다면, 스왑
	if (d < c) swap(c, d);
	// ccw가 0이면 평행임
	// 여기서 if 조건문이 true가 되어 return false가 되려면, ccw != 0이어야 함. 즉, 한 직선에 있지 않거나,
	// cd선분이 ab선분 오른쪽에 있어 안겹치거나, ab선분이 cd선분 오른쪽에 있어 안겹치면 바로 false
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;
	// 여기 아래로 실행문이 내려온다는 것은 (ccw(a, b, c) == 0 && b >= c && d >= a)이다.
	// 겹치는 경우다. 교차점은 큰 쪽의 점이다...
	if (a < c)
		p = c;
	else p = a;
	return true;
}

// p가 (a, b)를 감싸면서 각 변이 x, y축에 평행한 최소 사각형 내부에 있는지 확인한다.
// a, b, p는 일직선 상에 있다고 가정한다.
// b를 오른쪽 상단, a를 왼쪽 하단 점인 직사각형 모양을 상상해라. p는 직사각형의 대각선인 선분 ab에 있을 수도 없을 수도 있다.
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
{
	if (b < a) swap(a, b);
	// p가 a점이거나 b점이면 직사각형 내부에 있다, 또는 p가 a의 우상단에 있으면서 p가 b의 좌하단에 있으면 대각선에 위치한다는 의미다.
	return p == a || p == b || (a < p&& p < b);
}

// (a, b)선분과 (c, d)선분의 교점을 p에 반환한다.
// 교점이 여러 개일 경우 아무 점이나 반환한다.
// 두 선분이 교차하지 않을 경우 false를 반환한다.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p)
{
	// 두 직선이 평행인 경우를 우선 예외로 처리한다.
	// lineIntersection함수는 두 직선이 기울기가 달라 겹치는 경우 true이다.
	// 만약 두 직선이 평행하거나 겹치는 경우 false임. false일 경우 parallelSegments 호출
	if (!lineIntersection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);
	// p가 두 선분에 포함되어 있는 경우에만 참을 반환한다.
	// p는 이미 위의 lineIntersection에서 계산됨. 이 교차점 p가 선분 ab안에 있고, 선분 cd 안에 있어야만 true, 아니면 false
	return inBoundingRectangle(p, a, b) &&
		inBoundingRectangle(p, c, d);
}

// 교차점이 필요없고 선분 교차 검사만 수행하는 알고리즘
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d)
{
	// ccw(a, b, c)는 벡터ab를 기준으로 벡터ac가 시계방향에 있으면 음수, 반시계방향에 있으면 양수
	// 두 선분이 교차하는 경우라면 ab, cd는 둘다 음수여야함.
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	// ab가 0인 경우는 두 가지 경우가 있다.
	// 1. ccw(a, b, c), ccw(a, b, d) 모두 0인 경우 => cd는 ab와 같은 직선상에 있거나, 끝점이 겹치는 경우다
	// (끝점이 겹치는 경우에는 두 선분의 기울기가 같아도 되고 달라도 된다)
	// 2. ccw(a, b, c)와 ccw(a, b, d) 둘 중 하나만 0인 경우 
	//		=> 0의 값을 갖는 점이 ab와 같은 직선상에 있다. 
	//		만약 ccw(a, b, c) == 0이라면 점 c는 ab와 같은 직선상에 있다. 
	//		점 d는 ab와 다른 직선상에 있다.
	//		또한 이런 경우 cd는 0이 아니게 됨.
	// 두 선분이 한 직선 위에 있거나 끝점이 겹치는 경우
	if (ab == 0 && cd == 0) {
		// 계산 편의성을 위해 줄 맞춰주고
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		// b < c(또는 d < a)이면 두 선분은 만나지 않으니까 ! 붙여서 false 반환. 만약 (b >= c && d >= a)이면 true 반환임. 
		return !(b < c || d < a);
	}
	// 어찌됐든 두 선분이 한 직선위에 있지 않으면, ab와 cd가 둘 다 음수여야만(또는 하나만 음수이고, 하나는 0도 가능) true.
	return ab <= 0 && cd <= 0;
}

// 점 p에서 (a, b) 직선에 내린 수선의 발을 구한다.
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b)
{
	return a + (p - a).project(b - a);
}

// 점 p와 (a, b) 직선 사이의 거리를 구한다.
double pointToLine(vector2 p, vector2 a, vector2 b)
{
	return (p - perpendicularFoot(p, a, b)).norm();
}