//描述
//	Harmony is indispensible in our daily life and no one can live without it----may be Facer is the only exception.
//	One day it is rumored that repeat painting will create harmony and then hundreds of people started their endless drawing.
//	Their paintings were based on a small template and a simple method of duplicating.
//	Though Facer can easily imagine the style of the whole picture, but he cannot find the essential harmony.
//	Now you need to help Facer by showing the picture on computer.
//	You will be given a template containing only one kind of character and spaces, 
//	and the template shows how the endless picture is created
//	----use the characters as basic elements and put them in the right position to form a bigger template, 
//	and then repeat and repeat doing that.
//输入描述：
//	The input contains multiple test cases.
//	The first line of each case is an integer N, representing the size of the template is N*N(N could only be 3, 4 or 5).
//	Next N lines describe the template.The following line contains an integer Q, which is the Scale Level of the picture.
//	Input is ended with a case of N = 0. 
//	It is guaranteed that the size of one picture will not exceed 3000 * 3000.
//输出描述：
//	For each test case, just print the Level Q picture by using the given template.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> Painting;

Painting scale_up(const Painting &basic_t, const Painting &pre_paint, const int N, const int scale_to_paint);
void draw(const Painting &p);

int main()
{
	int N;
	while (cin >> N)
	{
		if (N == 0)
		{
			break;
		}
		// 清除空格
		getchar();
		// 获取模板
		Painting paint_t;
		for (int i = 0; i < N; i++)
		{
			string temp;
			getline(cin, temp);
			paint_t.push_back(temp);
		}
		// 扩建次数
		int Q;
		cin >> Q;
		Painting painting;
		// 初始绘制第一行的第一个元素为非空格字符
		painting.push_back("1");
		for (int i = 0, scale = N; i < Q; i++)
		{
			painting = scale_up(paint_t, painting, N, scale);
			scale *= N;
		}
		draw(painting);
	}
	return 0;
}

Painting scale_up(const Painting &basic_t, const Painting &pre_paint, const int N, const int scale_to_paint)
{
	Painting scaled_painting;
	for (int i = 0; i < scale_to_paint; i++)
	{
		string line;
		for (int j = 0; j < scale_to_paint; j++)
		{
			// 获取当前位置相当于上一次画作的位置
			int pre_paint_rpos = i / N;
			int pre_paint_cpos = j / N;
			// 如果对应上次画作的位置非空格，则绘制模板
			if (pre_paint[pre_paint_rpos][pre_paint_cpos] != ' ')
			{
				// 获取当前位置相当于上一次画作的位置
				int pre_templ_rpos = i % N;
				int pre_templ_cpos = j % N;
				line.push_back(basic_t[pre_templ_rpos][pre_templ_cpos]);
			}
			else
			{
				// 如果是空格则返回空格
				line.push_back(' ');
			}
		}
		scaled_painting.push_back(line);
	}
	return scaled_painting;
}

void draw(const Painting &p)
{
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}
}