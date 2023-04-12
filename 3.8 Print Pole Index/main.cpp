//����
//	��һ�����������ϣ������±�Ϊi��������������������������ڵ������� ����С�����������ڵ���������Ƹ�����Ϊһ����ֵ�㣬��ֵ����±����i��
//
//����������
//	ÿ��������һ��Ϊ������Ԫ�ظ���k(4��k��80)���ڶ�����k��������ÿ��������֮���ÿո�ָ�
//
//���������
//	ÿ���������Ϊn�����֣�����nΪ�ð����м�ֵ��ĸ�������ÿ�����ֶ�Ӧ��Ӧ�������Ӧ��ֵ���±�ֵ���±�ֵ֮���ÿո�ָ���
#include <iostream>
#include <vector>

using namespace std;

bool is_pole(int *data, int i, int k);

int main()
{
	int k;
	while (cin >> k)
	{
		int *data = new int[k];
		for (int i = 0; i < k; i++)
		{
			cin >> data[i];
		}
		vector<int> poles;
		for (int i = 0; i < k; i++)
		{
			if (is_pole(data, i, k))
			{
				poles.push_back(i);
			}
		}
		int size = poles.size();
		for (int i = 0; i < size - 1; i++)
		{
			cout << poles[i] << ' ';
		}
		cout << poles[size - 1] << endl;
	}
}

bool is_pole(int *data, int i, int k)
{
	if (i == 0 && i + 1 < k)
	{
		if (data[i] != data[i + 1])
		{
			return true;
		}
		else return false;
	}
	else if (i + 1 < k)
	{
		if ((data[i] - data[i + 1])*(data[i] - data[i - 1]) > 0)
		{
			return true;
		}
		else return false;
	}
	else if (i + 1 == k)
	{
		if (data[i - 1] != data[i])
		{
			return true;
		}
		else return false;
	}
	return false;
}