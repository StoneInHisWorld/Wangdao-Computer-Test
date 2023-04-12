//描述
//	按要求，给国家进行排名。
//
//输入描述：
//	有多组数据。 第一行给出国家数N，要求排名的国家数M，国家号从0到N - 1。 
//	第二行开始的N行给定国家或地区的奥运金牌数，奖牌数，人口数（百万）。 
//	接下来一行给出M个国家号。
// 
//输出描述：
//	排序有4种方式 : 金牌总数 奖牌总数 金牌人口比例 奖牌人口比例 对每个国家给出最佳排名排名方式 和 最终排名 
//	格式为 : 排名:排名方式 如果有相同的最终排名，则输出排名方式最小的那种排名，
//	对于排名方式，金牌总数 < 奖牌总数 < 金牌人口比例 < 奖牌人口比例 
//	如果有并列排名的情况，即如果出现金牌总数为 100, 90, 90, 80.
//	则排名为1, 2, 2, 4. 每组数据后加一个空行。
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

struct Country
{
	int no;
	int gold_count;
	int medal_count;
	int population;
	double gold_ra;
	double medal_ra;
};

enum Rank_Meth
{
	By_Gold = 1, By_Medal, By_Gold_Ra, By_Medal_Ra
};

using Rank = pair<int, Rank_Meth>; // 排名名次，排名方式
using Countries = vector<Country>; // 排名名次，排名方式

void mergesort(Countries & data, int start, int end, Rank_Meth method);
void merge(Countries& data, int start, int mid, int end, Rank_Meth method);
bool compare(Country cl, Country cr, Rank_Meth method);
void update_rank(double & last_data, Country cur_coun, int & rank, int index, Rank_Meth method);
bool isNAN(double val);

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		Countries countries = Countries(N);
		for (int i = 0; i < N; i++)
		{
			cin >> countries[i].gold_count >> countries[i].medal_count >> countries[i].population;
			countries[i].no = i;
			countries[i].gold_ra = countries[i].gold_count / (double)countries[i].population;
			// 处理NAN
			if (isNAN(countries[i].gold_ra))
			{
				countries[i].gold_ra = 0;
			}
			countries[i].medal_ra = countries[i].medal_count / (double)countries[i].population;
			if (isNAN(countries[i].medal_ra))
			{
				countries[i].medal_ra = 0;
			}
		}
		// 存储排名信息，排名国家序号，最好排名，最好排名方式
		map<int, Rank> CounNo_to_Rank;
		for (int i = 0; i < M; i++)
		{
			int no;
			cin >> no;
			CounNo_to_Rank.insert({ no, Rank(N, By_Medal_Ra) });
		}
		for (int method = 1; method <= 4; method++)
		{
			int rank = 0;
			mergesort(countries, 0, N - 1, (Rank_Meth)method);
			double last_data = -1;
			for (int i = 0; i < N; i++)
			{
				int no = countries[i].no;
				update_rank(last_data, countries[i], rank, i, (Rank_Meth)method);
				auto res = CounNo_to_Rank.find(no);
				// 是需要更新的国家
				if (res != CounNo_to_Rank.end())
				{
					int rank_in_store = (*res).second.first;
					if (rank_in_store > rank)
					{
						// 更新最好排名以及排名方式
						(*res).second.first = rank;
						(*res).second.second = (Rank_Meth)method;
					}
				}
			}
		}
		for (auto & c2r : CounNo_to_Rank)
		{
			cout << c2r.second.first << ":" << (int)c2r.second.second << endl;
		}
		//for (auto c2r = CounNo_to_Rank.begin(); c2r != CounNo_to_Rank.end(); c2r++)
		//{
		//	cout << (*c2r).second.first << ":" << (int)(*c2r).second.second << endl;
		//}
		cout << endl;
	}
}

void mergesort(Countries & data, int low, int high, Rank_Meth method)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(data, low, mid, method);
		mergesort(data, mid + 1, high, method);
		merge(data, low, mid, high, method);
	}
}

void merge(Countries & data, int low, int mid, int high, Rank_Meth method)
{
	Countries temp = Countries(high + 1);
	for (int i = low; i <= high; i++) temp[i] = data[i];
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high)
	{
		if (compare(temp[i], temp[j], method))
		{
			data[k++] = temp[i++];
		}
		else
		{
			data[k++] = temp[j++];
		}
	}
	while (i <= mid) data[k++] = temp[i++];
	while (j <= high) data[k++] = temp[j++];
}

bool compare(Country cl, Country cr, Rank_Meth method)
{
	switch (method)
	{
	case By_Gold: return cl.gold_count > cr.gold_count;
	case By_Medal: return cl.medal_count > cr.medal_count;
	case By_Gold_Ra: return cl.gold_ra > cr.gold_ra;
		return cl.gold_count / (double)cl.population > cr.gold_count / (double)cr.population;
	case By_Medal_Ra: return cl.medal_ra > cr.medal_ra;
		return cl.medal_count / (double)cl.population > cr.medal_count / (double)cr.population;
	default: return false;
	}
}

void update_rank(double & last_data, Country cur_coun, int &rank, int index, Rank_Meth method)
{
	double cur_data;
	switch (method)
	{
	case By_Gold:cur_data = cur_coun.gold_count;
		break;
	case By_Medal:cur_data = cur_coun.medal_count;
		break;
	case By_Gold_Ra:cur_data = cur_coun.gold_count / (double)cur_coun.population;
		break;
	default:cur_data = cur_coun.medal_count / (double)cur_coun.population;
		break;
	}
	if (cur_data != last_data) rank = index + 1;
	last_data = cur_data;
	return;
}

bool isNAN(double val)
{
	if (val == val)
	{
		return false;
	}
	else
	{
		return true;
	}
}