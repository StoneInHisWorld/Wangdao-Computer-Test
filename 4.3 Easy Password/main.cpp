//����
//	Julius Caesar����ʹ�ù�һ�ֺܼ򵥵����롣 
//	���������е�ÿ���ַ�������������ĸ���к�5λ��Ӧ���ַ������棬�����͵õ������ġ� 
//	�����ַ�A��F�����档���������ĺ��������ַ��Ķ�Ӧ��ϵ�� 
//	���� A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
//	���� V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 
//	��������ǶԸ��������Ľ��н��ܵõ����ġ� ����Ҫע����ǣ������г��ֵ���ĸ���Ǵ�д��ĸ��������Ҳ��������ĸ���ַ�������Щ�ַ����ý��н��롣
//
//����������
//	�����еĲ������ݲ�����100�顣ÿ�����ݶ������µ���ʽ�����Ҹ����������֮��û�пհ׵��С� 
//	һ��������ݰ��������֣� 
//	1.    ��ʼ�� - һ�У������ַ��� "START" 
//	2.    ���� - һ�У��������ģ����Ĳ�Ϊ�գ��������е��ַ���������200 
//	3.    ������ - һ�У������ַ��� "END" �����һ���������֮����һ�У������ַ��� "ENDOFINPUT"��
//
//���������
//��ÿ�����ݣ�����һ��������������Ķ�Ӧ�����ġ�
#include <iostream>
#include <string>

using namespace std;

char replace(const char &c);

int main()
{
	string str;
	//while (true)
	//{
	//	// get start
	//	getline(cin, str);
	//	if (str == "ENDOFINPUT")
	//	{
	//		break;
	//	}
	//	getline(cin, str);
	//	for (int i = 0; i < str.size(); i++)
	//	{
	//		str[i] = replace(str[i]);
	//	}
	//	cout << str << endl;
	//	getline(cin, str);
	//}
	while (cin >> str)
	{
		// earse enter
		getchar();
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = replace(str[i]);
		}
		cout << str << endl;
		getline(cin, str);
	}
}

char replace(const char &c)
{
	if (c >= 'F' && c <= 'Z')
	{
		return c - 5;
	}
	else if (c >= 'A' && c <= 'E')
	{
		return 'V' + c - 'A';
	}
	else return c;
}