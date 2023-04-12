//描述
//	对给定的一个字符串，找出有重复的字符，并给出其位置，如：abcaaAB12ab12 
//	输出：a，1；a，4；a，5；a，10，b，2；b，11，1，8；1，12， 2，9；2，13。
//
//输入描述：
//	输入包括一个由字母和数字组成的字符串，其长度不超过100。
//
//输出描述：
//	可能有多组测试数据，对于每组数据， 按照样例输出的格式将字符出现的位置标出。 
//	1、下标从0开始。 2、相同的字母在一行表示出其出现过的位置。
#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;
using Poses = list<int>;
using Rep_ch_to_Poses = list < pair<char, Poses> > ;

void insert(Rep_ch_to_Poses &rc2p, char ch, int pos);

int main()
{
	string str;
	while (cin >> str)
	{
		Rep_ch_to_Poses rc2p;
		int i = 0;
		for (auto &c : str)
		{
			insert(rc2p, c, i++);
		}
		// 输出
		for (auto &rcp : rc2p)
		{
			int size = rcp.second.size();
			char ch = rcp.first;
			if (size > 1)
			{
				auto pi = rcp.second.begin();
				// 重复元素则输出位置信息
				for (int i = 0; i < size - 1; i++)
				{
					cout << ch << ":" << *(pi++) << ",";
				}
				cout << ch << ":" << *(pi++) << endl;
			}
		}
	}
}

void insert(Rep_ch_to_Poses &rc2p, char ch, int pos)
{
	// 查找
	for (auto &p : rc2p)
	{
		// 若已记录该种字符
		if (p.first == ch)
		{
			p.second.push_back(pos);
			return;
		}
	}
	Poses new_pos = Poses();
	new_pos.push_back(pos);
	rc2p.push_back(pair<char, Poses>(ch, new_pos));
}