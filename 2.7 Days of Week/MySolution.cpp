//#define _CRT_SECURE_NO_WARNINGS
//#define ERROR -1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//enum Month
//{
//	Janurary = 1, February, March, April, May, June, July, August, September,
//	October, November, December
//};
//
//int countDays_inLY(int mon, int day);
//int countDays_notInLY(int mon, int day);
//int extract_ymd(int *year, int *mon, int *day, char *input);
//int map_day(char *day_s);
//int map_month(char *mon_s);
//int map_year(char *year_s);
//
//int main()
//{
//	int day, mon, year;
//	char input[50];
//	while (scanf("%d", &day) != EOF)
//	{
//		char mon_s[10] = {0};
//		scanf("%s", mon_s);
//		mon = map_month(mon_s);
//		scanf("%d", &year);
//		//if (extract_ymd(&year, &mon, &day, input) == ERROR)
//		//{
//		//	printf("ERROR\n");
//		//} 
//		int isLeapYear = year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
//		if (isLeapYear)
//		{
//			//int count = countDays_inLY(mon, year);
//			//if (count == ERROR)
//			//{
//			//	printf("%d年%d月没有%d天", year, mon, year);
//			//}
//			//else
//			//{
//			//	printf("%d\n", count);
//			//}
//		}
//		else
//		{
//			//int count = countDays_notInLY(mon, year);
//			//if (count == ERROR)
//			//{
//			//	printf("%d年%d月没有%d天", year, mon, year);
//			//}
//			//else
//			//{
//			//	printf("%d\n", count);
//			//}
//		}
//	}
//	return 0;
//}
//
//int extract_ymd(int *year, int *mon, int *day, char *input)
//{
//	int i = 0;
//	char day_s[2] = { 0 };
//	// 提取天
//	while (input[i] != '\0' && input[i] != ' ')
//	{
//		day_s[i] = input[i];
//		i++;
//	}
//	*day = map_day(day_s);
//	char mon_s[10] = { 0 };
//	// 提取月份
//	while (input[i] != '\0' && input[i] != ' ')
//	{
//		mon_s[i] = input[i];
//		i++;
//	}
//	*mon = map_month(mon_s);
//	char year_s[10] = { 0 };
//	// 提取月份
//	while (input[i] != '\0' && input[i] != ' ')
//	{
//		year_s[i] = input[i];
//		i++;
//	}
//	*year = map_year(year_s);
//	return 0;
//}
//
//int map_day(char *day_s)
//{
//	int day = 0, len_s = strlen(day_s);
//	// 天数有两位
//	if (len_s == 2)
//	{
//		day += day_s[0] - 48;
//		day *= 10;
//		day += day_s[1] - 48;
//	}
//	else if (len_s == 1)
//	{
//		day += day_s[0] - 48;
//	}
//	else
//	{
//		return ERROR;
//	}
//}
//
//int map_month(char *mon_s)
//{
//	if (strcmp(mon_s, "Janurary") == 0)
//	{
//		return 1;
//	}
//	else if (strcmp(mon_s, "February") == 0)
//	{
//		return 2;
//	}
//	else if (strcmp(mon_s, "March") == 0)
//	{
//		return 3;
//	}
//	else if (strcmp(mon_s, "April") == 0)
//	{
//		return 4;
//	}
//	else if (strcmp(mon_s, "May") == 0)
//	{
//		return 5;
//	}
//	else if (strcmp(mon_s, "June") == 0)
//	{
//		return 6;
//	}
//	else if (strcmp(mon_s, "July") == 0)
//	{
//		return 7;
//	}
//	else if (strcmp(mon_s, "August") == 0)
//	{
//		return 8;
//	}
//	else if (strcmp(mon_s, "September") == 0)
//	{
//		return 9;
//	}
//	else if (strcmp(mon_s, "October") == 0)
//	{
//		return 10;
//	}
//	else if (strcmp(mon_s, "November") == 0)
//	{
//		return 11;
//	}
//	else if (strcmp(mon_s, "December") == 0)
//	{
//		return 12;
//	}
//	else
//	{
//		return ERROR;
//	}
//}
//
//int map_year(char *year_s)
//{
//	int year = 0, len_s = strlen(year_s);
//	// 年数有四位
//	if (len_s == 4)
//	{
//		year += (year_s[0] - 48)* 1000;
//		year += (year_s[1] - 48) * 100;		
//		year += (year_s[2] - 48) * 10;
//		year += year_s[3] - 48;
//		return year;
//	}
//	else
//	{
//		return ERROR;
//	}
//}
//
//int countDays_inLY(int mon, int day)
//{
//	switch (mon)
//	{
//	case Janurary:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case February:
//		if (day > 29 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case March:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case April:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case May:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case June:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case July:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case August:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case September:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case October:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case November:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	default:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	}
//	int count = 0;
//	// 去掉本月
//	mon--;
//	int num_sma = mon / 2;
//	if (mon >= 8 && mon % 2 == 0)
//	{
//		num_sma--;
//	}
//	int num_big = mon - num_sma;
//	// 额外计算二月
//	if (mon >= 2)
//	{
//		count += 29;
//		num_sma--;
//	}
//	return count + num_sma * 30 + num_big * 31 + day;
//}
//
//int countDays_notInLY(int mon, int day)
//{
//	switch (mon)
//	{
//	case Janurary:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case February:
//		if (day > 28 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case March:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case April:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case May:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case June:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case July:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case August:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case September:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case October:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	case November:
//		if (day > 30 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	default:
//		if (day > 31 || day < 1)
//		{
//			return ERROR;
//		}
//		break;
//	}
//	int count = 0;
//	// 去掉本月
//	mon--;
//	int num_sma = mon / 2;
//	if (mon >= 8 && mon % 2 == 0)
//	{
//		num_sma--;
//	}
//	int num_big = mon - num_sma;
//	// 额外计算二月
//	if (mon >= 2)
//	{
//		count += 28;
//		num_sma--;
//	}
//	return count + num_sma * 30 + num_big * 31 + day;
//}
//
//char *day_of_week(int year, int no_day)
//{
//	// 距离2000年1月1日有多少天
//	
//	switch (no_day % 7)
//	{
//	default:
//		break;
//	}
//}