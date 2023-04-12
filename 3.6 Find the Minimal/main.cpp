//描述
//	第一行输入一个数n，1 <= n <= 1000，下面输入n行数据，每一行有两个数，分别是x y。
//	输出一组x y，该组数据是所有数据中x最小，且在x相等的情况下y最小的。
//
//输入描述：
//输入有多组数据。 每组输入n，然后输入n个整数对。
//
//输出描述：
//输出最小的整数对。
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int *left, int *right);

int main()
{
	int n;
	while (cin >> n)
	{
		int **data = new int*[n];
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[2];
			cin >> data[i][0] >> data[i][1];
		}
		sort(data, data + n, compare);
		cout << data[0][0] << ' ' << data[0][1];
		delete[] data;
	}
}

bool compare(int *left, int *right)
{
	if (left[0] == right[0])
	{
		return left[1] < right[1];
	}
	return left[0] < right[0];
}