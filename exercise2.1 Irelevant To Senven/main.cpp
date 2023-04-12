//描述：
// 一个正整数, 如果它能被7整除, 或者它的十进制表示法中某个位数上的数字为7, 则称其为与7相关的数.
// 现求所有小于等于n(n < 100)的与7无关的正整数的平方和。
//输入描述：
//	案例可能有多组。对于每个测试案例输入为一行, 正整数n, (n < 100)
//输出描述：
//	对于每个测试案例输出一行，输出小于等于n的与7无关的正整数的平方和。
#include <iostream>

using namespace std;

bool is_irrelevant_to_7(int sample);

int main()
{
	int n;
	while (cin >> n)
	{
		int square_sum = 0;
		for (int i = 1; i < n + 1; i++)
		{
			if (is_irrelevant_to_7(i))
			{
				square_sum += i * i;
			}
		}
		cout << square_sum << endl;
	}
	return 0;
}

bool is_irrelevant_to_7(int sample)
{
	if (sample % 7 == 0)
	{
		return false;
	}
	else
	{
		// 检查某位数字是否为7
		while (sample != 0)
		{
			if (sample % 10 == 7)
			{
				return false;
			}
			else
			{
				sample /= 10;
			}
		}
	}
	return true;
}