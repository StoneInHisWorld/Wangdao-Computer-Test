//����
//����һϵ������������������������(����ж����������һ������)������ʣ�µ����������������ʣ������������ - 1��
//
//����������
//�����һ�а���1������N��1 <= N <= 1000�������������ݵĸ����� ��������һ����N��������
//
//���������
//�����ж���������ݣ�����ÿ�����ݣ� ��һ�����һ������������N�������е����ֵ��������ֵ��������ȥ������ʣ�µ����������� �ڶ��н�����Ľ�������
#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int *data, int N);

int main()
{
	int N;
	while (cin >> N)
	{
		int *data = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> data[i];
		}
		bubble_sort(data, N);
		cout << data[N - 1] << endl;
		for (int i = 0; i < N - 1; i++)
		{
			cout << data[i] << ' ';
		}
		if (N == 1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << endl;
		}
	}
}

void bubble_sort(int *data, int N)
{
	bool flag;
	int time = 0;
	do
	{
		flag = false;
		for (int i = 0; i < N - time - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				int temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
				flag = true;
			}
		}
		time++;
	} while (flag == true);
}
