#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pile(char pattern[80][80], int top, int left, int bot,
	int right, char who);
void output(char pattern[80][80], int top, int left, int bot,
	int right);
void cut_corner(char pattern[80][80], int top, int left, int bot,
	int right);

int main()
{
	int size = 0;
	char inner, outter;
	while (scanf("%d %c %c", &size, &inner, &outter) != EOF)
	{
		if (size % 2 == 0 || size <= 0 || size >= 80)
		{
			continue;
		}
		char pattern[80][80] = {'\0'};
		// 从小到大叠筐
		int top = size / 2, bot = top, left = top, right = top;
		char who = inner;
		// i为叠筐序数
		for (int i = 1; i <= size / 2 + 1; i++)
		{
			pile(pattern, top, left, bot, right, 
				i % 2 == 1 ? inner:outter);
			top--;
			bot++;
			left--;
			right++;
		}
		if (size != 1)
		{
			cut_corner(pattern, ++top, ++left, --bot, --right);
		}
		output(pattern, top, left, bot, right);
	}
}

void pile(char pattern[80][80], int top, int left, int bot,
	int right, char who)
{
	// 围上横边
	for (int i = left; i <= right; i++)
	{
		pattern[top][i] = who;
	}
	// 围下横边
	for (int i = left; i <= right; i++)
	{
		pattern[bot][i] = who;
	}
	// 围竖边
	for (int i = top; i < bot; i++)
	{
		pattern[i][left] = who;
		pattern[i][right] = who;
	}
}

void output(char pattern[80][80], int top, int left, int bot,
	int right)
{
	for (int i = top; i <= bot; i++)
	{
		for (int j = left; j <= right; j++)
		{
			printf("%c", pattern[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void cut_corner(char pattern[80][80], int top, int left, int bot,
	int right)
{
	pattern[top][left] = ' ';
	pattern[top][right] = ' ';
	pattern[bot][left] = ' ';
	pattern[bot][right] = ' ';
}
