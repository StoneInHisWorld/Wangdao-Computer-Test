//����
//����һ���ַ�������������A - Z��д��ĸ���ֵĴ���
//
//����������
//���������ж��飬ÿ����������Ϊһ���ַ�����
//
//���������
//��ÿ��������A - Z��˳��������д�д��ĸ���ֵĴ�����
#include <iostream>
#include <map>
#include <string>

using namespace std;
using AlphaCounts = map<char, int>;

void output(const AlphaCounts &ac);
void count(AlphaCounts &ac, const char &c);

int main()
{
	AlphaCounts ac;
	for (int i = 'A'; i <= 'Z'; i++)
	{
		ac[i] = 0;
	}
	while (cin.peek() != EOF)
	{
		string input;
		getline(cin, input);
		for (char &c : input)
		{
			count(ac, c);
		}
		output(ac);
	}
	return 0;
}

void count(AlphaCounts &ac, const char &c)
{
	if (c >= 'A' && c <= 'Z')
	{
		ac[c]++;
	}
}

void output(const AlphaCounts &ac)
{
	for (auto &p : ac)
	{
		cout << p.first << ":" << p.second << endl;
	}
}