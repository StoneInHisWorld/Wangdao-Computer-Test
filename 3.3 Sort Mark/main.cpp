//描述
//查找和排序
//题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列, 相同成绩
//都按先录入排列在前的规则处理。
//
//示例：
//jack      70
//peter     96
//Tom       70
//smith     67
//
//从高到低  成绩
//peter     96
//jack      70
//Tom       70
//smith     67
//
//从低到高
//smith     67
//jack      70
//Tom      70
//peter     96
//
//输入描述：
//注意一个case里面有多组样例，请用循环处理输入
//输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开。
//输出描述：
//按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
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