//描述
//	Among grandfather's papers a bill was found.     
//	72 turkeys $_679_     
//	The first and the last digits of the number that obviously represented the total price of those turkeys are replaced here by blanks 
//	(denoted _), for they are faded and are illegible. 
//	What are the two faded digits and what was the price of one turkey?     
//	We want to write a program that solves a general version of the above problem.     
//	N turkeys $_XYZ_     
//	The total number of turkeys, N, is between 1 and 99, including both. 
//	The total price originally consisted of five digits, but we can see only the three digits in the middle. 
//	We assume that the first digit is nonzero, that the price of one turkeys is an integer number of dollars, 
//	and that all the turkeys cost the same price.     
//	Given N, X, Y and Z, write a program that guesses the two faded digits and the original price. 
//	In case that there is more than one candidate for the original price, the output should be the most expensive one. 
//	That is, the program is to report the two faded digits and the maximum price per turkey for the turkeys.
//输入描述：
//	The first line of the input file contains an integer N(0 < N < 100), which represents the number of turkeys.In the following line, 
//	there are the three decimal digits X, Y, and Z., separated by a space, of the original price $_XYZ_.
//输出描述：
//	For each case, output the two faded digits and the maximum price per turkey for the turkeys.
#include <iostream>

using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		int X, Y, Z;
		int turkey_price = 0, bill_i = -1, bill_j = -1;
		cin >> X >> Y >> Z;
		// 万位
		for (int i = 1; i < 10; i++)
		{
			// 个位
			for (int j = 0; j < 10; j++)
			{
				int bill_price = i * 10000 + X * 1000 + Y * 100 + Z * 10 + j;
				if (bill_price % N == 0 && bill_price / N > turkey_price)
				{
					turkey_price = bill_price / N;
					bill_i = i;
					bill_j = j;
				}
			}
		}
		if (bill_i == -1 && bill_j == -1)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << bill_i << ' ' << bill_j << ' ' << turkey_price << endl;
		}
	}
}