//描述
//输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出 - 1）。
// 
//输入描述：
//测试数据有多组，输入n(1 <= n <= 200)，接着输入n个数，然后输入x。
//
//输出描述：
//对于每组输入, 请输出结果。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int *data = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}
		int x;
		cin >> x;
		int i;
		for (i = 0; i < n; i++)
		{
			if (data[i] == x)
				break;
		}
		if (i == n)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
}