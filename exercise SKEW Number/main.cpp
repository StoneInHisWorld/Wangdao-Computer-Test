//����
//	�� skew binary ��ʾ�У��� k λ��ֵ x[k] ��ʾ x[k]��(2 ^ (k + 1) - 1)��
//	ÿ��λ�ϵĿ��������� 0 �� 1�������һ������λ������ 2��
//	���磬10120(skew) = 1��(2 ^ 5 - 1) + 0��(2 ^ 4 - 1) + 1��(2 ^ 3 - 1) + 2��(2 ^ 2 - 1) + 0��(2 ^ 1 - 1) = 31 + 0 + 7 + 6 + 0 = 44��
//	ǰʮ�� skew ���� 0��1��2��10��11��12��20��100��101���Լ� 102��
//
//����������
//	��������������ݣ�ÿ�����ݰ���һ�� skew ����
//
//���������
//	��Ӧÿһ�����ݣ������Ӧ��ʮ������ʽ����������� 2 ^ 31 - 1��
#include <iostream>
#include <list>

using namespace std;
using Numbers = list<int>;

Numbers split(int src);
Numbers get_numbers();

int main()
{
	while (cin.peek() != EOF)
	{
		Numbers numbers = get_numbers();
		int num_digits = numbers.size();
		int decimal = 0, i = 1;
		for (auto &digit : numbers)
		{
			decimal += digit * (pow(2, i++) - 1);
		}
		cout << decimal << endl;
	}
}

Numbers split(int src)
{
	Numbers numbers;
	if (src == 0)
	{
		numbers.push_back(0);
	}
	else
	{
		while (src != 0)
		{
			numbers.push_back(src % 10);
			src /= 10;
		}
	}
	return numbers;
}

Numbers get_numbers()
{
	Numbers numbers;
	char c = getchar();
	while (c != '\n')
	{
		numbers.push_front(c - '0');
		c = getchar();
	}
	return numbers;
}