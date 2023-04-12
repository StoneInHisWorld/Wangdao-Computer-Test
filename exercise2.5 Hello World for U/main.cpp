//ÃèÊö
//	Given any string of N(>= 5) characters, you are asked to form the characters into the shape of U.
//	For example, "helloworld" can be printed as : h  d e  l l  r lowo 
//	That is, the characters must be printed in the original order, 
//	starting top - down from the left vertical line with n1 characters, 
//	then left to right along the bottom line with n2 characters, and finally bottom - up along the vertical line with n3 characters.
//	And more, we would like U to be as squared as possible -- 
//	that is, it must be satisfied that n1 = n3 = max{ k | k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
//ÊäÈëÃèÊö£º
//	There are multiple test cases.
//	Each case contains one string with no less than 5 and no more than 80 characters in a line.
//	The string contains no white space.
//Êä³öÃèÊö£º
//	For each test case, print the input string in the shape of U as specified in the description.
#include <iostream>
#include <string>

using namespace std;

void calculate(const int &N, int &height, int &width);
void draw(const string &s, const int &height, const int &width);

int main()
{
	string s;
	while (cin >> s)
	{
		int N = s.size();
		int height;
		int width;
		calculate(N, height, width);
		draw(s, height, width);
	}
}

void calculate(const int &N, int &height, int &width)
{
	height = N / 2;
	for (int i = 3; i - 2 < height; i++)
	{
		if ((N + 2 - i) % 2 != 0)
		{
			continue;
		}
		else
		{
			width = i;
			height = (N + 2 - width) / 2;
		}
	}
}

void draw(const string &s, const int &height, const int &width) 
{
	string::const_iterator si_b = s.begin();
	string::const_iterator si_e = s.end();
	for (int i = 0; i < height - 1; i++)
	{
		cout << *(si_b++);
		for (int j = 0; j < width - 2; j++) cout << ' ';
		cout << *(--si_e) << endl;
	}
	while (si_b != si_e) cout << *(si_b++);
	cout << endl;
}