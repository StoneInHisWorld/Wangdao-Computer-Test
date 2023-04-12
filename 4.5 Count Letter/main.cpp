//描述
//输入一行字符串，计算其中A - Z大写字母出现的次数
//
//输入描述：
//案例可能有多组，每个案例输入为一行字符串。
//
//输出描述：
//对每个案例按A - Z的顺序输出其中大写字母出现的次数。
#include <iostream>
#include <map>
#include <string>

using namespace std;
using AlphaCounts = map<char, int>;

void output(const AlphaCounts &ac);
void count(AlphaCounts &ac, const char &c);

int main()
{
	AlphaCounts ac;
	for (int i = 'A'; i <= 'Z'; i++)
	{
		ac[i] = 0;
	}
	while (cin.peek() != EOF)
	{
		string input;
		getline(cin, input);
		for (char &c : input)
		{
			count(ac, c);
		}
		output(ac);
	}
	return 0;
}

void count(AlphaCounts &ac, const char &c)
{
	if (c >= 'A' && c <= 'Z')
	{
		ac[c]++;
	}
}

void output(const AlphaCounts &ac)
{
	for (auto &p : ac)
	{
		cout << p.first << ":" << p.second << endl;
	}
}