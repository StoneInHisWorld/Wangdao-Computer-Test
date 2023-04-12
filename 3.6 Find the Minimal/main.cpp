//����
//	��һ������һ����n��1 <= n <= 1000����������n�����ݣ�ÿһ�������������ֱ���x y��
//	���һ��x y����������������������x��С������x��ȵ������y��С�ġ�
//
//����������
//�����ж������ݡ� ÿ������n��Ȼ������n�������ԡ�
//
//���������
//�����С�������ԡ�
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int *left, int *right);

int main()
{
	int n;
	while (cin >> n)
	{
		int **data = new int*[n];
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[2];
			cin >> data[i][0] >> data[i][1];
		}
		sort(data, data + n, compare);
		cout << data[0][0] << ' ' << data[0][1];
		delete[] data;
	}
}

bool compare(int *left, int *right)
{
	if (left[0] == right[0])
	{
		return left[1] < right[1];
	}
	return left[0] < right[0];
}