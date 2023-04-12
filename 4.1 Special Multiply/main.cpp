//描述
//写个算法，对2个小于1000000000的输入，求结果。 特殊乘法举例：123 * 45 = 1 * 4 + 1 * 5 + 2 * 4 + 2 * 5 + 3 * 4 + 3 * 5
//
//输入描述：
//两个小于1000000000的数
//
//输出描述：
//输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果。
#include <iostream>
#include <vector>

using namespace std;
using Multipliers = vector<int>;

void extract_num(int mul, Multipliers &res);

int main()
{
	int mul1, mul2;
	while (cin >> mul1 >> mul2)
	{
		Multipliers multipliers1, multipliers2;
		int sum = 0;
		extract_num(mul1, multipliers1);
		extract_num(mul2, multipliers2);
		for (auto m1 : multipliers1)
		{
			for (auto m2 : multipliers2)
			{
				sum += m1 * m2;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

void extract_num(int mul, Multipliers &res)
{
	if (mul == 0)
	{
		res.insert(res.begin(), mul % 10);
	}
	else
	{
		while (mul != 0)
		{
			// 将mul每个数字插入到结果数组中
			res.insert(res.begin(), mul % 10);
			mul /= 10;
		}
	}
	return;
}

