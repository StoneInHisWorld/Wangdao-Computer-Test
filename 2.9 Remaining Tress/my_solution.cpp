#define _CRT_SECURE_NO_WARNINGS
//描述
//有一个长度为整数L(1 <= L <= 10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，
//即在0, 1, 2，...，L共L + 1个位置上有L + 1棵树。     
//现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。     
//可能有M(1 <= M <= 100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。

//输入描述：
//两个整数L(1 <= L <= 10000)和M(1 <= M <= 100)。     接下来有M组整数，每组有一对数字。

//输出描述：
//可能有多组输入数据，对于每组输入数据，输出一个数，表示移走所有区间的树之后剩下的树的个数。
#include <stdio.h>
#include <stdlib.h>

typedef struct duration {
	int lower;
	int upper;
}DUR;

int merge(DUR *d1, DUR *d2);
void swap(DUR *d1, DUR *d2);

//int main() 
//{
//	int L, M;
//	scanf("%d %d", &L, &M);
//	DUR *dur = (DUR *)malloc(M * sizeof(DUR));
//	for (int i = 0; i < M; i++)
//	{
//		scanf("%d %d", &dur[i].lower, &dur[i].upper);
//	}
//	// 合并
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = i+1; j < M; j++)
//		{
//			// 如果可以合并就合并
//			if (merge(&dur[i], &dur[j]))
//			{
//				swap(&dur[j], &dur[M - 1]);
//				//free(&dur[M - 1]);
//				M--;
//			}
//		}
//	}
//	int n_trees_to_removed = 0;
//	for (int i = 0; i < M; i++)
//	{
//		n_trees_to_removed += dur[i].upper - dur[i].lower + 1;
//	}
//	printf("%d", L + 1 - n_trees_to_removed);
//}

int merge(DUR *d1, DUR *d2)
{
	// 未进行合并则输出0，否则输出1
	if (d2->lower < d1->lower)
	{
		if (d2->upper < d1->lower)
		{
			return 0;
		}
		else if (d2->upper <= d1->upper)
		{
			d1->lower = d2->lower;
		}
		else
		{
			d1->lower = d2->lower;
			d1->upper = d2->upper;
		}
	}
	else if (d2->lower >= d1->lower && d2->lower <= d1->upper)
	{
		if (d2->upper > d1->upper)
		{
			d1->upper = d2->upper;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

void swap(DUR *d1, DUR *d2)
{
	DUR temp = *d1;
	*d1 = *d2;
	*d2 = temp;
	return;
}

