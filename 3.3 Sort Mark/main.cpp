//����
//���Һ�����
//��Ŀ���������⣨�û����ɼ������У����Ի�óɼ��Ӹߵ��ͻ�ӵ͵��ߵ�����, ��ͬ�ɼ�
//������¼��������ǰ�Ĺ�����
//
//ʾ����
//jack      70
//peter     96
//Tom       70
//smith     67
//
//�Ӹߵ���  �ɼ�
//peter     96
//jack      70
//Tom       70
//smith     67
//
//�ӵ͵���
//smith     67
//jack      70
//Tom      70
//peter     96
//
//����������
//ע��һ��case�����ж�������������ѭ����������
//������У�������Ҫ������˵ĸ�����Ȼ���������򷽷�0�����򣩻���1�������ٷֱ��������ǵ����ֺͳɼ�����һ���ո������
//���������
//����ָ����ʽ������ֺͳɼ������ֺͳɼ�֮����һ���ո����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct STU
{
	int id;
	string name;
	int mark;
}STU;

bool compare_ascend(STU s_l, STU s_r);
bool compare_descend(STU s_l, STU s_r);
void output_stu(STU *stu, int N);

int main()
{
	int N;
	while (cin >> N)
	{
		bool ascend;
		cin >> ascend;
		STU *stus = new STU[N];
		for (int i = 0; i < N; i++)
		{
			stus[i].id = i;
			cin >> stus[i].name;
			cin >> stus[i].mark;
		}
		if (ascend)
		{
			sort(stus, stus + N, compare_ascend);
		}
		else
		{
			sort(stus, stus + N, compare_descend);
		}
		output_stu(stus, N);
	}
	return 0;
}

bool compare_ascend(STU s_l, STU s_r)
{
	if (s_l.mark == s_r.mark)
	{
		return s_l.id < s_r.id;
	}
	else
	{
		return s_l.mark < s_r.mark;
	}
}

bool compare_descend(STU s_l, STU s_r)
{
	if (s_l.mark == s_r.mark)
	{
		return s_l.id < s_r.id;
	}
	else
	{
		return s_l.mark > s_r.mark;
	}
}

void output_stu(STU *stu, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << stu[i].name << ' ' << stu[i].mark << endl;
	}
}