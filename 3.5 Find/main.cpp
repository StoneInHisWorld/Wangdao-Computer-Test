//描述
//输入数组长度 n 输入数组      a[1...n] 输入查找个数m 输入查找数字b[1...m]   输出 YES or NO  查找有则YES 否则NO 。
//
//输入描述：
//输入有多组数据。 每组输入n，然后输入n个整数，再输入m，然后再输入m个整数（1 <= m, n <= 100）。
//
//输出描述：
//如果在n个数组中输出YES否则输出NO。
#include <iostream>
#include <string>

using namespace std;

#define SUCCESS "YES"
#define FAIL "NO"

string find(int *data, int to_find, int n);

int main()
{
	int n;
	while (cin >> n)
	{
		int *data = new int[n];
		int m;
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}
		cin >> m;
		int *to_find = new int[m];
		for (int i = 0; i < m; i++)
		{
			cin >> to_find[i];
		}
		for (int i = 0; i < m; i++)
		{
			cout << find(data, to_find[i], n) << endl;
		}
	}
}

string find(int *data, int to_find, int n)
{
	int i = 0;
	while (data[i] != to_find && i < n) i++;
	if (i < n)
	{
		return SUCCESS;
	}
	else
	{
		return FAIL;
	}
}