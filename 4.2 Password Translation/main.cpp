//����
//	���鱨���ݹ����У�Ϊ�˷�ֹ�鱨���ػ�������Ҫ���鱨��һ���ķ�ʽ���ܣ��򵥵ļ����㷨��Ȼ��������ȫ�����鱨�����룬����Ȼ�ܷ�ֹ�鱨�����׵�ʶ��
//	���Ǹ���һ����򵥵ļ��ܷ������Ը�����һ���ַ����������д�a - y, A - Y����ĸ��������ĸ�������z��Z��a��A�������ɵõ�һ���򵥵ļ����ַ�����
//
//����������
//��ȡ��һ���ַ�����ÿ���ַ�������С��80���ַ�
//
//���������
//����ÿ�����ݣ����ÿ���ַ����ļ����ַ�����
#include <iostream>
#include <string>

using namespace std;

char replace(const char &c);

int main()
{
	string str;
	while (cin.peek() != EOF)
	{
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = replace(str[i]);
		}
		cout << str << endl;
	}
	return 0;
}

char replace(const char &c)
{
	if ((c < 'z' && c >= 'a') || c >= 'A' && c < 'Z')
	{
		return c + 1;
	}
	else if (c == 'z')
	{
		return 'a';
	}
	else if (c == 'Z')
	{
		return 'A';
	}
	else return c;
}