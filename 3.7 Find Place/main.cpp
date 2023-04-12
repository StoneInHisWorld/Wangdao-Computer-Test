//����
//	�Ը�����һ���ַ������ҳ����ظ����ַ�����������λ�ã��磺abcaaAB12ab12 
//	�����a��1��a��4��a��5��a��10��b��2��b��11��1��8��1��12�� 2��9��2��13��
//
//����������
//	�������һ������ĸ��������ɵ��ַ������䳤�Ȳ�����100��
//
//���������
//	�����ж���������ݣ�����ÿ�����ݣ� ������������ĸ�ʽ���ַ����ֵ�λ�ñ���� 
//	1���±��0��ʼ�� 2����ͬ����ĸ��һ�б�ʾ������ֹ���λ�á�
#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;
using Poses = list<int>;
using Rep_ch_to_Poses = list < pair<char, Poses> > ;

void insert(Rep_ch_to_Poses &rc2p, char ch, int pos);

int main()
{
	string str;
	while (cin >> str)
	{
		Rep_ch_to_Poses rc2p;
		int i = 0;
		for (auto &c : str)
		{
			insert(rc2p, c, i++);
		}
		// ���
		for (auto &rcp : rc2p)
		{
			int size = rcp.second.size();
			char ch = rcp.first;
			if (size > 1)
			{
				auto pi = rcp.second.begin();
				// �ظ�Ԫ�������λ����Ϣ
				for (int i = 0; i < size - 1; i++)
				{
					cout << ch << ":" << *(pi++) << ",";
				}
				cout << ch << ":" << *(pi++) << endl;
			}
		}
	}
}

void insert(Rep_ch_to_Poses &rc2p, char ch, int pos)
{
	// ����
	for (auto &p : rc2p)
	{
		// ���Ѽ�¼�����ַ�
		if (p.first == ch)
		{
			p.second.push_back(pos);
			return;
		}
	}
	Poses new_pos = Poses();
	new_pos.push_back(pos);
	rc2p.push_back(pair<char, Poses>(ch, new_pos));
}