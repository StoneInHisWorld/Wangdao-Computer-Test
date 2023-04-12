//����
//д���㷨����2��С��1000000000�����룬������ ����˷�������123 * 45 = 1 * 4 + 1 * 5 + 2 * 4 + 2 * 5 + 3 * 4 + 3 * 5
//
//����������
//����С��1000000000����
//
//���������
//��������ж������ݣ�����ÿһ�����ݣ����Input�е�������������ĿҪ��ķ������������õ��Ľ����
#include <iostream>
#include <vector>

using namespace std;
using Multipliers = vector<int>;

void extract_num(int mul, Multipliers &res);

int main()
{
	int mul1, mul2;
	while (cin >> mul1 >> mul2)
	{
		Multipliers multipliers1, multipliers2;
		int sum = 0;
		extract_num(mul1, multipliers1);
		extract_num(mul2, multipliers2);
		for (auto m1 : multipliers1)
		{
			for (auto m2 : multipliers2)
			{
				sum += m1 * m2;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

void extract_num(int mul, Multipliers &res)
{
	if (mul == 0)
	{
		res.insert(res.begin(), mul % 10);
	}
	else
	{
		while (mul != 0)
		{
			// ��mulÿ�����ֲ��뵽���������
			res.insert(res.begin(), mul % 10);
			mul /= 10;
		}
	}
	return;
}

