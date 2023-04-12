//描述
//	在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。
//	我们给出一种最简单的加密方法，对给定的一个字符串，把其中从a - y, A - Y的字母用其后继字母替代，把z和Z用a和A替代，则可得到一个简单的加密字符串。
//
//输入描述：
//读取这一行字符串，每个字符串长度小于80个字符
//
//输出描述：
//对于每组数据，输出每行字符串的加密字符串。
#include <iostream>
#include <string>

using namespace std;

char replace(const char &c);

int main()
{
	string str;
	while (cin.peek() != EOF)
	{
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = replace(str[i]);
		}
		cout << str << endl;
	}
	return 0;
}

char replace(const char &c)
{
	if ((c < 'z' && c >= 'a') || c >= 'A' && c < 'Z')
	{
		return c + 1;
	}
	else if (c == 'z')
	{
		return 'a';
	}
	else if (c == 'Z')
	{
		return 'A';
	}
	else return c;
}