#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int L, M;
	while (scanf("%d %d", &L, &M) != EOF)
	{
		int *tree = (int *)malloc((L + 1) * sizeof(int));
		// 一棵树存活状态则为1，死亡状态即为0
		for (int i = 0; i < L + 1; i++)
		{
			tree[i] = 1;
		}
		for (int i = 0; i < M; i++)
		{
			int lower, upper;
			scanf("%d %d", &lower, &upper);
			memset(&tree[lower], 0, upper - lower + 1);
			for (int i = lower; i <= upper; i++)
			{
				tree[i] = 0;
			}
		}
		int trees_alive = 0;
		for (int i = 0; i < L + 1; i++)
		{
			if (1 == tree[i])
			{
				trees_alive++;
			}
		}
		printf("%d\n", trees_alive);
	}
}