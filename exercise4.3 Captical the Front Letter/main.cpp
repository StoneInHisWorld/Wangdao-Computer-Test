//描述
//	对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。 
//	在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
//
//输入描述：
//	输入一行：待处理的字符串（长度小于100）。
//
//输出描述：
//	可能有多组测试数据，对于每组数据， 输出一行：转换后的字符串。
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Words = vector<string>;
using Seperators = string;

Words split(const Words &src, const char &with);
Words split(const string &src, const char &with);
void capitalise(Words &src);
void output(const Words &src, const Seperators &seps);
Seperators collect_sep(const string &src);

int main()
{
	while (cin.peek() != EOF)
	{
		string str;
		getline(cin, str);
		Words res = split(split(split(split(str, ' '), '\t'), '\r'), '\n');
		capitalise(res);
		Seperators sep = collect_sep(str);
		output(res, sep);
	}
}

Words split(const string &src, const char &with)
{
	Words words;
	int size = src.size();
	size_t i = 0;
	while (true)
	{
		size_t begin = i;
		i = src.find(with, begin);
		string sub_str = src.substr(begin, i - begin);
		words.push_back(sub_str);
		if (i++ == string::npos)
		{
			break;
		}
	}
	return words;
}

Words split(const Words &src, const char &with)
{
	Words words;
	for (auto &str : src)
	{
		Words res = split(str, with);
		words.insert(words.end(), res.begin(), res.end());
	}
	return words;
}

void capitalise(Words &src)
{
	for (auto &word : src)
	{
		if (word[0] <= 'z' && word[0] >= 'a')
		{
			word[0] -= 32;
		}
	}
}

void output(const Words &src, const Seperators &seps)
{
	size_t size = src.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		cout << src[i] << seps[i];
	}
	cout << src[size - 1] << endl;
}

Seperators collect_sep(const string &src)
{
	Seperators seperators;
	int size = src.size();
	for (size_t i = 0; i < size; i++)
	{
		if (src[i] == ' ' || src[i] == '\t' || src[i] == '\n' || src[i] == '\r')
		{
			seperators.push_back(src[i]);
		}
	}
	return seperators;
}