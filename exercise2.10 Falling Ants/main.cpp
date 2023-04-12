//描述
//	一根长度为1米的木棒上有若干只蚂蚁在爬动。它们的速度为每秒一厘米或静止不动，方向只有两种，向左或者向右。
//	如果两只蚂蚁碰头，则它们立即交换速度并继续爬动。三只蚂蚁碰头，则两边的蚂蚁交换速度，中间的蚂蚁仍然静止。
//	如果它们爬到了木棒的边缘（0或100厘米处）则会从木棒上坠落下去。
//	在某一时刻蚂蚁的位置各不相同且均在整数厘米处（即1，2，3，…99厘米），有且只有一只蚂蚁A速度为0，其他蚂蚁均在向左或向右爬动。
//	给出该时刻木棒上的所有蚂蚁位置和初始速度，找出蚂蚁A从此时刻到坠落所需要的时间。
//输入描述：
//	第一行包含一个整数表示蚂蚁的个数N（2 <= N <= 99），之后共有N行，每一行描述一只蚂蚁的初始状态。
//	每个初始状态由两个整数组成，中间用空格隔开，第一个数字表示初始位置厘米数P（1 <= P <= 99），
//	第二个数字表示初始方向, -1表示向左，1表示向右，0表示静止。
//输出描述：
//	蚂蚁A从开始到坠落的时间。若不会坠落，输出“Cannot fall!”
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define STICK_LEN 100 // cm
#define ANT_SPEED 1 // cm

typedef enum direction {
	L = -1, S, R
}orien;

typedef struct ant {
	orien dir;
	double pos;
	ant(int dir, double pos) :dir((orien)dir), pos(pos) {};
	bool operator==(ant r) 
	{ return this->dir == r.dir && this->pos == r.pos; }
}ANT;
typedef vector<ANT> ANTS;
typedef ANTS::iterator i_ants;

void update_ants(ANTS &ants, int &ant_a);
bool compare(ANT l, ANT r);
void swap(orien &o1, orien &o2);
bool all_stay_put(const ANTS &ants);

int main()
{
	int N;
	while (cin >> N)
	{
		ANTS ants;
		for (int i = 0; i < N; i++)
		{
			int dir;
			double pos;
			cin >> pos >> dir;
			ants.push_back(ant(dir, pos));
		}
		sort(ants.begin(), ants.end(), compare);
		int a_index = 0;
		// 找A
		while (ants.at(a_index).dir != S) a_index++;
		bool a_has_fallen = false;
		// 开始计时，每秒更新蚂蚁状态
		double time;
		for (time = 0; a_has_fallen == false; time += 0.5)
		{
			update_ants(ants, a_index);
			if (a_index == -1 || a_index == ants.size())
			{
				a_has_fallen = true;
			}
			if (all_stay_put(ants))
			{
				time += 0.5;
				break;
			}
		}
		if (a_has_fallen)
		{
			cout << (int)time << endl;
		}
		else
		{
			cout << "Cannot fall!" << endl;
		}
	}
}

bool all_stay_put(const ANTS &ants)
{
	ANTS::const_iterator aci = ants.begin();
	while (aci != ants.end() && aci->dir == S) aci++;
	if (aci == ants.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void update_ants(ANTS &ants, int &ant_a)
{
	// 更新位置
	for (i_ants ia = ants.begin(); ia < ants.end(); ia++)
	{
		ia->pos += ia->dir * (ANT_SPEED / 2.0);
	}
	// 更新方向
	for (i_ants ia = ants.begin(); ia < ants.end(); ia++)
	{
		double pos1 = ia->pos;
		if (ia + 1 != ants.end())
		{
			double pos2 = (ia + 1)->pos;
			// 如果两只蚂蚁位置相同则交换速度
			if (pos1 == pos2)
			{
				if (ia + 2 != ants.end())
				{
					double pos3 = (ia + 2)->pos;
					// 如果三只蚂蚁相同则交换两边蚂蚁的速度
					if (pos3 == pos2)
					{
						swap(ia->dir, (ia + 2)->dir);
						ia += 2;
					}
					else
					{
						swap(ia->dir, (ia + 1)->dir);
						ia++;
					}
				}
				else
				{
					swap(ia->dir, (ia + 1)->dir);
					ia++;
				}
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
	}
	// 处理掉落的蚂蚁
	ANT ant_l = *ants.begin();
	ANT ant_r = *ants.rbegin();
	if (ant_l.pos == 0)
	{
		ants.erase(ants.begin());
		ant_a--;
	}
	if (ant_r.pos == 100)
	{
		ants.pop_back();
	}
}

bool compare(ANT l, ANT r)
{
	return l.pos < r.pos;
}

void swap(orien &o1, orien &o2)
{
	orien temp = o1;
	o1 = o2;
	o2 = temp;
}
