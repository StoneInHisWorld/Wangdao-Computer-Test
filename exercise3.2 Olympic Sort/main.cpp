//����
//	��Ҫ�󣬸����ҽ���������
//
//����������
//	�ж������ݡ� ��һ�и���������N��Ҫ�������Ĺ�����M�����ҺŴ�0��N - 1�� 
//	�ڶ��п�ʼ��N�и������һ�����İ��˽����������������˿��������򣩡� 
//	������һ�и���M�����Һš�
// 
//���������
//	������4�ַ�ʽ : �������� �������� �����˿ڱ��� �����˿ڱ��� ��ÿ�����Ҹ����������������ʽ �� �������� 
//	��ʽΪ : ����:������ʽ �������ͬ�����������������������ʽ��С������������
//	����������ʽ���������� < �������� < �����˿ڱ��� < �����˿ڱ��� 
//	����в����������������������ֽ�������Ϊ 100, 90, 90, 80.
//	������Ϊ1, 2, 2, 4. ÿ�����ݺ��һ�����С�
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

using Rank = pair<int, Rank_Meth>; // �������Σ�������ʽ
using Countries = vector<Country>; // �������Σ�������ʽ

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
			// ����NAN
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
		// �洢������Ϣ������������ţ�������������������ʽ
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
				// ����Ҫ���µĹ���
				if (res != CounNo_to_Rank.end())
				{
					int rank_in_store = (*res).second.first;
					if (rank_in_store > rank)
					{
						// ������������Լ�������ʽ
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