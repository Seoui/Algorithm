#include "���Ͼ˰���.h"

int main()
{
	vector2 a(3.0, 1.0);
	vector2 b(10.0, 5.0);
	vector2 c(6.0, 7.0);
	vector2 d(8.0, 1.0);
	vector2 p(0.0, 0.0);
	cout << "���� ���� �˻� ���: " << segmentIntersection(a, b, c, d, p) << endl;
	cout << "������ ��ǥ: " << p.x << " " << p.y << endl;

}