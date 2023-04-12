//描述
//输入10个整数，彼此以空格分隔。重新排序以后输出(也按空格分隔)，
//要求: 1.先输出其中的奇数, 并按从大到小排列； 2.然后输出其中的偶数, 并按从小到大排列。
//输入描述：
//任意排序的10个整数（0～100），彼此以空格分隔。
//输出描述：
//可能有多组测试数据，对于每组数据，按照要求排序后输出，由空格分隔。 
//1. 测试数据可能有很多组，请使用while(cin >> a[0] >> a[1] >> ... >> a[9])类似的做法来实现; 
//2. 输入数据随机，有可能相等。
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b);

int main()
{
	int a[10];
	while (cin >> a[0])
	{
		for (int i = 1; i < 10; i++)
		{
			cin >> a[i];
		}
		// 降序
		sort(a, a + 10, compare);
		for (int i = 0; i < 10; i++)
		{
			if (a[i] % 2 == 1)
			{
				cout << a[i] << ' ';
			}
		}
		// 升序
		sort(a, a + 10);
		for (int i = 0; i < 10; i++)
		{
			if (a[i] % 2 == 0)
			{
				cout << a[i] << ' ';
			}
		}
		cout << endl;
	}
}

// 返回真则不交换
bool compare(int a, int b)
{
	return a > b;
}