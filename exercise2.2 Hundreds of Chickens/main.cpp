//描述
//用小于等于n元去买100只鸡，大鸡5元 / 只，小鸡3元 / 只, 还有1 / 3元每只的一种小鸡，分别记为x只, y只, z只。编程求解x, y, z所有可能解。
//（本题没有测试数据，
//int main() {}
//就能通过
//真·本地过了就是过了）
//
//输入描述：
//测试数据有多组，输入n。
//输出描述：
//对于每组输入, 请输出x, y, z所有可行解，按照x，y，z依次增大的顺序输出。
#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		// 买x只大鸡
		for (int x = 0; x <= 100; x++)
		{
			// 买y只小鸡
			for (int y = 0; y <= 100 - x; y++)
			{
				int z = 100 - x - y;
				double expense = 5 * x + 3 * y + z / 3.0;
				// 如果钱没花完
				if (n >= expense)
				{
					cout << "x=" << x << ",";
					cout << "y=" << y << ",";
					cout << "z=" << z << endl;
				}
			}
		}
	}
}
