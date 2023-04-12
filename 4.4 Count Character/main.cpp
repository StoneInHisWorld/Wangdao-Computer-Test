//描述
//	统计一个给定字符串中指定的字符出现的次数。
//
//输入描述：
//	测试输入包含若干测试用例，每个测试用例包含2行，第1行为一个长度不超过5的字符串，第2行为一个长度不超过80的字符串。
//	注意这里的字符串包含空格，即空格也可能是要求被统计的字符之一。当读到'#'时输入结束，相应的结果不要输出。
//
//输出描述：
//	对每个测试用例，统计第1行中字符串的每个字符在第2行字符串中出现的次数，按如下格式输出：     c0 n0     c1 n1     c2 n2     ...     
//	其中ci是第1行中第i个字符，ni是ci出现的次数。
#include <iostream>
#include <string>
#include <list>

using namespace std;
using Res = pair<string, int>;
using ResList = list<Res>;
using TarList = list<string>;

Res find(const char &target, const string &des);

int main()
{
	while (cin.peek() != EOF)
	{
		string target;
		getline(cin, target);
		if (target == "#")
		{
			break;
		}
		//// erase enter
		//char c = getchar();
		//while (c != '\n')
		//{
		//	target += c;
		//	c = getchar();
		//}
		// 查找源
		string des;
		getline(cin, des);
		for (char &c : target)
		{
			Res res = find(c, des);
			cout << res.first << ' ' << res.second << endl;
		}
	}
	return 0;
}

Res find(const char &target, const string &des)
{
	Res res;
	res.first = target;
	res.second = 0;
	int des_size = des.size();
	for (int i = 0; i < des_size; i++)
	{
		// 子串尾下标
		// int sub_str = (i + target_size - 1 < des_size) ? (i + target_size - 1) : (des_size - 1);
		// 字符相等则计数
		if (des[i] == target)
		{
			res.second++;
		}
	}
	return res;
}