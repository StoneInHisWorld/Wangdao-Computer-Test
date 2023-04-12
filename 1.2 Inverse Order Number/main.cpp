#include <stdio.h>
#include <math.h>

int inverse(int origin, int level);

int main()
{
	for (int i = 1000; i < 9999; i++)
	{
		int nine_times = i * 9;
		if (nine_times > 9999)
		{
			break;
		}
		if (inverse(i, 4) == nine_times)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

int inverse(int origin, int level)
{
	int op = origin;
	int result = 0;
	for (int i = 0; i < level; i++)
	{
		int digit = op % 10;
		result += digit * pow(10, level - i - 1);
		op /= 10;
	}
	return result;
}