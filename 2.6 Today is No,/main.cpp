#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, mon, day;
	// 0号位作废
	int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// 到i月1日之前有多少天（0号位作废）
	int totalDay[13] = {0};
	// 计算到i+1月1日之前有多少天
	for (int i = 2; i < 13; i++)
	{
		totalDay[i] = totalDay[i - 1] + mday[i - 1];
	}
	while (scanf("%d %d %d", &year, &mon, &day) != EOF)
	{
		int isLeap = year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
		if (isLeap && mon > 2)
		{
			printf("%d\n", totalDay[mon] + day + 1);
		}
		else
		{
			printf("%d\n", totalDay[mon] + day);
		}
	}
	return 0;
}