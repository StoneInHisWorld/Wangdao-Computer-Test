//����
//	ͳ��һ�������ַ�����ָ�����ַ����ֵĴ�����
//
//����������
//	��������������ɲ���������ÿ��������������2�У���1��Ϊһ�����Ȳ�����5���ַ�������2��Ϊһ�����Ȳ�����80���ַ�����
//	ע��������ַ��������ո񣬼��ո�Ҳ������Ҫ��ͳ�Ƶ��ַ�֮һ��������'#'ʱ�����������Ӧ�Ľ����Ҫ�����
//
//���������
//	��ÿ������������ͳ�Ƶ�1�����ַ�����ÿ���ַ��ڵ�2���ַ����г��ֵĴ����������¸�ʽ�����     c0 n0     c1 n1     c2 n2     ...     
//	����ci�ǵ�1���е�i���ַ���ni��ci���ֵĴ�����
#include <iostream>
#include <string>
#include <list>

using namespace std;
using Res = pair<string, int>;
using ResList = list<Res>;
using TarList = list<string>;

Res find(const char &target, const string &des);

int main()
{
	while (cin.peek() != EOF)
	{
		string target;
		getline(cin, target);
		if (target == "#")
		{
			break;
		}
		//// erase enter
		//char c = getchar();
		//while (c != '\n')
		//{
		//	target += c;
		//	c = getchar();
		//}
		// ����Դ
		string des;
		getline(cin, des);
		for (char &c : target)
		{
			Res res = find(c, des);
			cout << res.first << ' ' << res.second << endl;
		}
	}
	return 0;
}

Res find(const char &target, const string &des)
{
	Res res;
	res.first = target;
	res.second = 0;
	int des_size = des.size();
	for (int i = 0; i < des_size; i++)
	{
		// �Ӵ�β�±�
		// int sub_str = (i + target_size - 1 < des_size) ? (i + target_size - 1) : (des_size - 1);
		// �ַ���������
		if (des[i] == target)
		{
			res.second++;
		}
	}
	return res;
}