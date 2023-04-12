//描述
//	输入一个字符串，以回车结束（字符串长度 <= 100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。
//	现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
//
//输入描述：
//	每组数据输入包括3行，第1行是包含多个单词的字符串s，第2行是待替换的单词a(长度 <= 100)，第3行是a将被替换的单词b(长度 <= 100)。
//	s, a, b 最前面和最后面都没有空格。
//
//输出描述：
//每个测试数据输出只有 1 行， 将s中所有单词a替换成b之后的字符串。
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Words = vector<string>;

Words split(const string &src);

int main()
{
	while (cin.peek() != EOF)
	{
		string src, a, b;
		getline(cin, src);
		cin >> a >> b;
		Words words = split(src);
		for (auto &word : words)
		{
			if (word == a)
			{
				word = b;
			}
		}
		size_t i = 0, size = words.size();
		for (size_t i = 0; i < size - 1; i++)
		{
			cout << words[i] << ' ';
		}
		cout << words[size - 1] << endl;
	}
}

Words split(const string &src)
{
	Words words;
	int size = src.size();
	size_t i = 0;
	while (true)
	{
		size_t begin = i;
		i = src.find(' ', begin);
		string sub_str = src.substr(begin, i - begin);
		words.push_back(sub_str);
		if (i++ == string::npos)
		{
			break;
		}
	}
	return words;
}