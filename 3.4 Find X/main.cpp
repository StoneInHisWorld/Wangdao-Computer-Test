//����
//����һ����n��Ȼ������n����ֵ������ͬ��������һ��ֵx��������ֵ����������е��±꣨��0��ʼ������������������� - 1����
// 
//����������
//���������ж��飬����n(1 <= n <= 200)����������n������Ȼ������x��
//
//���������
//����ÿ������, ����������
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