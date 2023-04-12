//����
//�������鳤�� n ��������      a[1...n] ������Ҹ���m �����������b[1...m]   ��� YES or NO  ��������YES ����NO ��
//
//����������
//�����ж������ݡ� ÿ������n��Ȼ������n��������������m��Ȼ��������m��������1 <= m, n <= 100����
//
//���������
//�����n�����������YES�������NO��
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