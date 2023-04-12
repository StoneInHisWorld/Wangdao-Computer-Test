#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 可以解决所有日期问题
int main()
{
	int year, n;
	// 0号位作废
	int mday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (scanf("%d %d", &year, &n) != EOF)
	{
		int mon = 1, day = 1;
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
		for (int i = 0; i < n-1; i++)
		{
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
		}
		printf("%4d-%02d-%02d\n", year, mon, day);
	}
	return 0;
}