//����
//	��дһ�������࣬Ҫ��xxxx - xx - xx �ĸ�ʽ������ڣ�ʵ�ּ�һ��Ĳ�����
//����������
//	�����һ�б�ʾ���������ĸ���m��������m��ÿ����3���ÿո�������������ֱ��ʾ�����ա��������ݲ��������ꡣ
//���������
//	���m�С���xxxx - xx - xx�ĸ�ʽ�������ʾ�������ڵĺ�һ������ڡ�
#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
public:
	Date();
	static void next_day(int &year, int &mon, int &day);
	static void output_ymd(int &year, int &mon, int &day);
	~Date();

private:

};

Date::Date()
{
}

void Date::next_day(int & year, int & mon, int & day)
{
	int mday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// ��������������2�µ���������
	int isLeap = year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
	if (isLeap)
	{
		mday[2] = 29;
	}
	else
	{
		mday[2] = 28;
	}
	day++;
	if (day > mday[mon])
	{
		++mon;
		day = 1;
		if (mon > 12)
		{
			mon = 1;
			++year;
		}
	}
	return;
}

void Date::output_ymd(int & year, int & mon, int & day)
{
	cout << year << '-' << setw(2) << setfill('0')
		<< mon << '-' << setw(2) << setfill('0') << day << endl;
}

Date::~Date()
{
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int year, mon, day;
		cin >> year >> mon >> day;
		Date::next_day(year, mon, day);
		Date::output_ymd(year, mon, day);
	}
}