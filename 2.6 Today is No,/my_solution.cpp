#define _CRT_SECURE_NO_WARNINGS
#define ERROR -1
#include <stdio.h>


enum Month
{
	Janurary = 1, February, March, April, May, June, July, August, September, 
	October, November, December
};

int countDays_inLY(int mon, int day);
int countDays_notInLY(int mon, int day);

int main()
{
	int day, mon, year;
	while (scanf("%d %d %d", &year, &mon, &day) != EOF)
	{
		int isLeapYear = year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
		if (isLeapYear)
		{
			int count = countDays_inLY(mon, day);
			if (count == ERROR)
			{
				printf("%d年%d月没有%d天", year, mon, day);
			}
			else
			{
				printf("%d\n", count);
			}
		}
		else
		{
			int count = countDays_notInLY(mon, day);
			if (count == ERROR)
			{
				printf("%d年%d月没有%d天", year, mon, day);
			}
			else
			{
				printf("%d\n", count);
			}
		}
	}
	return 0;
}

int countDays_inLY(int mon, int day)
{
	switch (mon)
	{
	case Janurary:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case February:
		if (day > 29 || day < 1)
		{
			return ERROR;
		}
		break;
	case March:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case April:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	case May:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case June:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	case July:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case August:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case September:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	case October:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case November:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	default:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	}
	int count = 0;
	// 去掉本月
	mon--;
	int num_sma = mon / 2;
	if (mon >= 8 && mon % 2 == 0)
	{
		num_sma--;
	}
	int num_big = mon - num_sma;
	// 额外计算二月
	if (mon >= 2)
	{
		count += 29;
		num_sma--;
	}
	return count + num_sma * 30 + num_big * 31 + day;
}

int countDays_notInLY(int mon, int day)
{
	switch (mon)
	{
	case Janurary:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case February:
		if (day > 28 || day < 1)
		{
			return ERROR;
		}
		break;
	case March:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case April:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	case May:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case June:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	case July:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case August:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case September:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	case October:
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	case November:
		if (day > 30 || day < 1)
		{
			return ERROR;
		}
		break;
	default: 
		if (day > 31 || day < 1)
		{
			return ERROR;
		}
		break;
	}
	int count = 0;
	// 去掉本月
	mon--;
	int num_sma = mon / 2;
	if (mon >= 8 && mon % 2 == 0)
	{
		num_sma--;
	}
	int num_big = mon - num_sma;
	// 额外计算二月
	if (mon >= 2)
	{
		count += 28;
		num_sma--;
	}
	return count + num_sma * 30 + num_big * 31 + day;
}