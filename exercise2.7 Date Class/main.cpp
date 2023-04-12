//描述
//	编写一个日期类，要求按xxxx - xx - xx 的格式输出日期，实现加一天的操作。
//输入描述：
//	输入第一行表示测试用例的个数m，接下来m行每行有3个用空格隔开的整数，分别表示年月日。测试数据不会有闰年。
//输出描述：
//	输出m行。按xxxx - xx - xx的格式输出，表示输入日期的后一天的日期。
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
	// 如果是闰年则更改2月的天数上限
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