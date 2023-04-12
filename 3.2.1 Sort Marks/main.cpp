//描述
//用一维数组存储学号和成绩，然后，按成绩排序输出。
//输入描述：
//输入第一行包括一个整数N(1 <= N <= 100)，代表学生的个数。 接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
//输出描述：
//按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。 如果学生的成绩相同，则按照学号的大小进行从小到大排序。
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct student {
	int id;
	int mark;
}STU;

bool compare(STU s1, STU s2);

int main()
{
	STU *stus = NULL;
	int N;
	while (cin >> N)
	{
		stus = new STU[N];
		for (int i = 0; i < N; i++)
		{
			cin >> stus[i].id;
			cin >> stus[i].mark;
		}
		sort(stus, stus + N, compare);
		for (int i = 0; i < N; i++)
		{
			cout << stus[i].id << ' ' << stus[i].mark << endl;
		}
	}
}

bool compare(STU s1, STU s2)
{
	if (s1.mark == s2.mark)
	{
		return s1.id < s2.id;
	}
	return s1.mark < s2.mark;
}