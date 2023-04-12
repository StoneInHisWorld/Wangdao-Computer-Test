//����
//	����һ���ַ������Իس��������ַ������� <= 100�������ַ��������ɸ�������ɣ�����֮����һ���ո���������е������ִ�Сд��
//	����Ҫ�����е�ĳ�������滻����һ�����ʣ�������滻֮����ַ�����
//
//����������
//	ÿ�������������3�У���1���ǰ���������ʵ��ַ���s����2���Ǵ��滻�ĵ���a(���� <= 100)����3����a�����滻�ĵ���b(���� <= 100)��
//	s, a, b ��ǰ�������涼û�пո�
//
//���������
//ÿ�������������ֻ�� 1 �У� ��s�����е���a�滻��b֮����ַ�����
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Words = vector<string>;

Words split(const string &src);

int main()
{
	while (cin.peek() != EOF)
	{
		string src, a, b;
		getline(cin, src);
		cin >> a >> b;
		Words words = split(src);
		for (auto &word : words)
		{
			if (word == a)
			{
				word = b;
			}
		}
		size_t i = 0, size = words.size();
		for (size_t i = 0; i < size - 1; i++)
		{
			cout << words[i] << ' ';
		}
		cout << words[size - 1] << endl;
	}
}

Words split(const string &src)
{
	Words words;
	int size = src.size();
	size_t i = 0;
	while (true)
	{
		size_t begin = i;
		i = src.find(' ', begin);
		string sub_str = src.substr(begin, i - begin);
		words.push_back(sub_str);
		if (i++ == string::npos)
		{
			break;
		}
	}
	return words;
}