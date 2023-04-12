//����
//	���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
//����������
//	�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
//���������
//	ÿ���������һ�У������ڲ�ֵ
#include <iostream>

using namespace std;

void extract_ymd(int date, int &year, int &mon, int &day);
void next_day(int &year, int &mon, int &day);

int main()
{
	int date1, date2;
	while (cin >> date1 >> date2)
	{
		int year1, mon1, day1;
		int year2, mon2, day2;
		int count = 1;
		extract_ymd(date1, year1, mon1, day1);
		extract_ymd(date2, year2, mon2, day2);
		while (year1 != year2 || mon1 != mon2 || day1 != day2)
		{
			count++;
			next_day(year1, mon1, day1);
		}
		cout << count << endl;
	}
}

void extract_ymd(int date, int &year, int &mon, int &day)
{
	day = date % 100;
	date /= 100;
	mon = date % 100;
	year = date / 100;
	return;
}

void next_day(int &year, int &mon, int &day)
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