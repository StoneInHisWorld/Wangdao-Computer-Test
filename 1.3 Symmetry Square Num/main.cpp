#include <stdio.h>
#include <math.h>

bool isSymmetry(int num);
int inverse(int origin, int level);
int getLevel(int num);

int main() 
{
	for (int i = 0; i <= 256; i++)
	{
		if (isSymmetry(i*i))
		{
			printf("%d\n", i);
		}
	}
}

bool isSymmetry(int num) 
{
	if (num == inverse(num, getLevel(num)))
	{
		return true;
	}
	return false;
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

int getLevel(int num) 
{
	int level = 0;
	while (num / pow(10, level) != 0)
	{
		level++;
		num /= 10;
	}
	return level;
}