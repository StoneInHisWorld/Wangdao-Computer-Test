//����
//	NֻС����(1 <= N <= 100)��ÿֻ��ͷ�ϴ���һ������ɫ��ñ�ӡ����ڳƳ�ÿֻ�����������Ҫ���հ��������Ӵ�С��˳���������ͷ��ñ�ӵ���ɫ��
//	ñ�ӵ���ɫ�á�red������blue�����ַ�������ʾ����ͬ��С������Դ���ͬ��ɫ��ñ�ӡ������������������ʾ��
// 
//����������
//	�స�����룬ÿ�������������һ��Ϊһ������N����ʾС�������Ŀ�� 
//	������N�У�ÿ����һֻ�������Ϣ����һ��Ϊ������100������������ʾ�����������
//	�ڶ���Ϊ�ַ�������ʾ�����ñ����ɫ���ַ������Ȳ�����10���ַ��� 
//	ע�⣺���������������ͬ��
//
//���������
//	ÿ���������հ���������Ӵ�С��˳����������ñ����ɫ��
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Mouse
{
	string hat;
	int weight;
};

bool compare(Mouse ml, Mouse mr);

int main()
{
	int N;
	while (cin >> N)
	{
		Mouse *m_s = new Mouse[N];
		for (int i = 0; i < N; i++)
		{
			cin >> m_s[i].weight;
			cin >> m_s[i].hat;
		}
		sort(m_s, m_s + N, compare);
		for (int i = 0; i < N; i++)
		{
			cout << m_s[i].hat << endl;
		}
	}
}

bool compare(Mouse ml, Mouse mr)
{
	return ml.weight > mr.weight;
}