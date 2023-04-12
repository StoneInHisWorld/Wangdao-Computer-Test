//描述
//	在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数， 或者小于所有它相邻的整数，则称该整数为一个极值点，极值点的下标就是i。
//
//输入描述：
//	每个案例第一行为此数组元素个数k(4＜k＜80)，第二行是k个整数，每两个整数之间用空格分隔
//
//输出描述：
//	每个案例输出为n个数字（其中n为该案例中极值点的个数）：每个数字对应相应数组的相应极值点下标值，下标值之间用空格分隔。
#include <iostream>
#include <vector>

using namespace std;

bool is_pole(int *data, int i, int k);

int main()
{
	int k;
	while (cin >> k)
	{
		int *data = new int[k];
		for (int i = 0; i < k; i++)
		{
			cin >> data[i];
		}
		vector<int> poles;
		for (int i = 0; i < k; i++)
		{
			if (is_pole(data, i, k))
			{
				poles.push_back(i);
			}
		}
		int size = poles.size();
		for (int i = 0; i < size - 1; i++)
		{
			cout << poles[i] << ' ';
		}
		cout << poles[size - 1] << endl;
	}
}

bool is_pole(int *data, int i, int k)
{
	if (i == 0 && i + 1 < k)
	{
		if (data[i] != data[i + 1])
		{
			return true;
		}
		else return false;
	}
	else if (i + 1 < k)
	{
		if ((data[i] - data[i + 1])*(data[i] - data[i - 1]) > 0)
		{
			return true;
		}
		else return false;
	}
	else if (i + 1 == k)
	{
		if (data[i - 1] != data[i])
		{
			return true;
		}
		else return false;
	}
	return false;
}