//描述
//We now use the Gregorian style of dating in Russia.
//The leap years are years with number divisible by 4 but not divisible by 100, or divisible by 400. 
//For example, years 2004, 2180 and 2400 are leap.Years 2005, 2181 and 2300 are not leap.
//Your task is to write a program which will compute the day of week corresponding to a given date 
//in the nearest past or in the future using today’s agreement about dating.
//输入描述：
//There is one single line contains the day number d, month name M and year number y(1000≤y≤3000).
//The month name is the corresponding English name starting from the capital letter.
//输出描述：
//Output a single line with the English name of the day of week corresponding to the date, 
//starting from the capital letter.All other letters must be in lower case.
//Month and Week name in Input / 
//Output: January, February, March, April, May, June, 
//	July, August, September, October, November, December Sunday, Monday, Tuesday, 
//	Wednesday, Thursday, Friday, Saturday
#define _CRT_SECURE_NO_WARNINGS
#define ERROR -1
// 天、月、年计算起始时间
#define DAY_SET 5
#define MON_SET 2
#define YEAR_SET 2023
#define WEEKDAY_SET 7
#include <iostream>
#include <string>
#include <map>

using namespace std;

int map_month(char *mon_s);
string map_weekday(int weekday_int);
void next_day(int &year, int &mon, int &day);

int main()
{
	map<string, int> weekday_str2num = {
	
	};
	int day, year;
	char mon_cs[10];
	while (scanf("%d%s%d", &day, mon_cs, &year) != EOF)
	{
		int mon = map_month(mon_cs);
		int isLeapYear = year % 400 == 0 
			|| year % 100 != 0 && year % 4 == 0;
		bool isBefore = year < YEAR_SET 
			|| YEAR_SET == year && mon < MON_SET
			|| YEAR_SET == year && MON_SET == mon && day < DAY_SET;
		// 从起点走到终点
		int beg_year, beg_mon, beg_day, end_year, end_mon, end_day;
		if (isBefore)
		{
			beg_year = year;
			beg_mon = mon;
			beg_day = day;
			end_year = YEAR_SET;
			end_mon = MON_SET;
			end_day = DAY_SET;
		}
		else
		{
			beg_year = YEAR_SET;
			beg_mon = MON_SET;
			beg_day = DAY_SET;
			end_year = year;
			end_mon = mon;
			end_day = day;
		}
		int total_day = 0;
		// 循环直至beg_date == end_date
		while (!(beg_year == end_year && 
			beg_mon == end_mon && beg_day == end_day))
		{
			total_day++;
			next_day(beg_year, beg_mon, beg_day);
		}
		// 如果是之前的日子
		if (isBefore)
		{
			int weekday = (6 - total_day % 7) % 7;
			cout << map_weekday(weekday) << endl;
		}
		else
		{
			int weekday = (total_day + 6) % 7;
			cout << map_weekday(weekday) << endl;
		}
	}
	return 0;
}

int map_month(char *mon_cs)
{
	map<string, int> mon_str2num = {
		{"January", 1},
		{"February", 2},
		{"March", 3},
		{"April", 4},
		{"May", 5},
		{"June", 6},
		{"July", 7},
		{"August", 8},
		{"September", 9},
		{"October", 10},
		{"November", 11},
		{"December", 12},
	};
	string mon_s = mon_cs;
	return mon_str2num[mon_s];
}

string map_weekday(int weekday_int)
{
	string weekday_int2str[7] = { "Monday", "Tuesday", 
		"Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	return weekday_int2str[weekday_int];
}

void next_day(int &year, int &mon, int &day) 
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