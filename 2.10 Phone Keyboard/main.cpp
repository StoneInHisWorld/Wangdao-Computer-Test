//描述
//按照手机键盘输入字母的方式，计算所花费的时间 如：a, b, c都在“1”键上，输入a只需要按一次，输入c需要连续按三次。 
//如果连续两个字符不在同一个按键上，则可直接按，如：ad需要按两下，kz需要按6下 
//如果连续两字符在同一个按键上，则两个按键之间需要等一段时间，如ac，在按了a之后，需要等一会儿才能按c。 
//现在假设每按一次需要花费一个时间段，等待时间需要花费两个时间段。 现在给出一串字符，需要计算出它所需要花费的时间。
//输入描述：
//一个长度不大于100的字符串，其中只有手机按键上有的小写字母
//输出描述：
//输入可能包括多组数据，对于每组数据，输出按出Input所给字符串所需要的时间
//九宫格键盘如下：
//1:    2:ABC 3:DEF
//4:GHI 5:JKL 6:MNO
//7:PQRS 8:TUV 9:WXYZ
#define _CRT_SECURE_NO_WARNINGS
#define PRESS_TIME 1
#define WAIT_TIME 2
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	map<char, int> char2btn = {
		{'a', 2}, {'b', 2}, {'c', 2},
		{'d', 3}, {'e', 3}, {'f', 3},
		{'g', 4}, {'h', 4}, {'i', 4},
		{'j', 5}, {'k', 5}, {'l', 5},
		{'m', 6}, {'n', 6}, {'o', 6},
		{'p', 7}, {'q', 7}, {'r', 7}, {'s', 7},
		{'t', 8}, {'u', 8}, {'v', 8},
		{'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}
	};
	map<char, int> char2press_times = {
		{'a', 1}, {'b', 2}, {'c', 3},
		{'d', 1}, {'e', 2}, {'f', 3},
		{'g', 1}, {'h', 2}, {'i', 3},
		{'j', 1}, {'k', 2}, {'l', 3},
		{'m', 1}, {'n', 2}, {'o', 3},
		{'p', 1}, {'q', 2}, {'r', 3}, {'s', 4},
		{'t', 1}, {'u', 2}, {'v', 3},
		{'w', 1}, {'x', 2}, {'y', 3}, {'z', 4}
	};
	char input[100];
	while (scanf("%s", input) != EOF)
	{
		int time = 0;
		char last_press_btn = 1;
		for (int i = 0; input[i] != '\0'; i++)
		{
			int cur_c = input[i];
			if (char2btn[cur_c] != last_press_btn)
			{
				time += char2press_times[cur_c];
			}
			else
			{
				time += WAIT_TIME + char2press_times[cur_c];
			}
			last_press_btn = char2btn[cur_c];
		}
		printf("%d\n", time);
	}
	return 0;
}