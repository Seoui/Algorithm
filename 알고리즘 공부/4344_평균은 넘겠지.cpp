#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c;
	int n;
	float point;
	vector<float> a;
	vector<float> higherThanAverage; //�����
	cin >> c;
	for (int i = 0; i < c; i++) // ���̽� ����
	{
		float sum = 0;
		float average = 0;
		int hta = 0; // ��պ��� ���� ���� ����
		cin >> n; // �л��� 
		for (int j = 0; j < n; j++)
		{
			cin >> point; // �� �л��� ����
			a.push_back(point);
			sum += point;
		}

		average = sum / (float)a.size(); //��� ���Ѱ���

		for (auto& element : a)
		{
			if (average < element)
				hta++;	// ��պ��� ���� ��� �� ���ϱ�
		}

		higherThanAverage.push_back((float)hta / (float)a.size() * 100);
		a.clear();
	}

	for (auto& i : higherThanAverage)
	{
		cout << fixed;
		cout.precision(3);
		cout << i << "%" << '\n';
	}

	return 0;
}