#include "기하알고리즘.h"

int main()
{
	vector2 a(3.0, 1.0);
	vector2 b(10.0, 5.0);
	vector2 c(6.0, 7.0);
	vector2 d(8.0, 1.0);
	vector2 p(0.0, 0.0);
	cout << "선분 교차 검사 결과: " << segmentIntersection(a, b, c, d, p) << endl;
	cout << "교차점 좌표: " << p.x << " " << p.y << endl;

}