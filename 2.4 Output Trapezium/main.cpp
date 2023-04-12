#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int h = 0;
	while (h < 1 || h > 1000)
	{
		scanf("%d", &h);
		if (h < 1 || h > 1000)
		{
			printf("Please input a number within (1, 1000)");
		}
	}
	// 逐层输出梯形
	for (int i = 0, num_CoupleSpace = h - 1, num_Star = h; i < h;
		i++, num_CoupleSpace -= 1, num_Star += 2)
	{
		for (int k = 0; k < num_CoupleSpace; k++)
		{
			printf("  ");
		}
		for (int k = 0; k < num_Star; k++)
		{
			printf("*");
		}
		printf("\n");
	}
		
}