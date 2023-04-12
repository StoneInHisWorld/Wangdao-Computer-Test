//����
//	һ������Ϊ1�׵�ľ����������ֻ���������������ǵ��ٶ�Ϊÿ��һ���׻�ֹ����������ֻ�����֣�����������ҡ�
//	�����ֻ������ͷ�����������������ٶȲ�������������ֻ������ͷ�������ߵ����Ͻ����ٶȣ��м��������Ȼ��ֹ��
//	�������������ľ���ı�Ե��0��100���״�������ľ����׹����ȥ��
//	��ĳһʱ�����ϵ�λ�ø�����ͬ�Ҿ����������״�����1��2��3����99���ף�������ֻ��һֻ����A�ٶ�Ϊ0���������Ͼ������������������
//	������ʱ��ľ���ϵ���������λ�úͳ�ʼ�ٶȣ��ҳ�����A�Ӵ�ʱ�̵�׹������Ҫ��ʱ�䡣
//����������
//	��һ�а���һ��������ʾ���ϵĸ���N��2 <= N <= 99����֮����N�У�ÿһ������һֻ���ϵĳ�ʼ״̬��
//	ÿ����ʼ״̬������������ɣ��м��ÿո��������һ�����ֱ�ʾ��ʼλ��������P��1 <= P <= 99����
//	�ڶ������ֱ�ʾ��ʼ����, -1��ʾ����1��ʾ���ң�0��ʾ��ֹ��
//���������
//	����A�ӿ�ʼ��׹���ʱ�䡣������׹�䣬�����Cannot fall!��
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
		// ��A
		while (ants.at(a_index).dir != S) a_index++;
		bool a_has_fallen = false;
		// ��ʼ��ʱ��ÿ���������״̬
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
	// ����λ��
	for (i_ants ia = ants.begin(); ia < ants.end(); ia++)
	{
		ia->pos += ia->dir * (ANT_SPEED / 2.0);
	}
	// ���·���
	for (i_ants ia = ants.begin(); ia < ants.end(); ia++)
	{
		double pos1 = ia->pos;
		if (ia + 1 != ants.end())
		{
			double pos2 = (ia + 1)->pos;
			// �����ֻ����λ����ͬ�򽻻��ٶ�
			if (pos1 == pos2)
			{
				if (ia + 2 != ants.end())
				{
					double pos3 = (ia + 2)->pos;
					// �����ֻ������ͬ�򽻻��������ϵ��ٶ�
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
	// ������������
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
