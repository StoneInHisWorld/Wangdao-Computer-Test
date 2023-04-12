//描述
//给你一串路径，譬如：
//a\b\c
//a\d\e
//b\cst
//d\
//你把这些路径中蕴含的目录结构给画出来，子目录直接列在父目录下面，并比父目录的首字符向右缩两个空格，就像这样：
//a
//b
//c
//d
//e
//b
//cst
//d
//注：同一级的需要按字母顺序排列，不能乱。
//输入描述：
//每个测试案例第一行为一个正整数n（n <= 10）表示有n个路径，当n为0时，测试结束，接下来有n行，每行有一个字串表示一个路径，长度小于50。
//输出描述：
//输出目录结构，每一个测试样例的输出紧跟一个空行。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define SPLIT '\\'
#define LEVEL_GAP "  "

typedef struct TNode {
	string s;
	struct TNode *lchild = NULL, *rbro = NULL;
	TNode(string s, struct TNode *l, struct TNode *r) :
		s(s), lchild(l), rbro(r){};
}TNode, *T;

typedef vector<T> Trees;

string get_next_dir(const string &line, string::const_iterator &index);
TNode *insert(TNode * parent, string dir);
void output_tree(T tree, int level);
bool compare(T t_l, T t_r);
T get_root(Trees &trees, string root);

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			return 0;
		}
		Trees trees;
		string last_root = "";
		for (int i = 0; i < n; i++)
		{
			string line;
			cin >> line;
			// 获取根目录
			string::const_iterator sci = line.begin();
			string dir = get_next_dir(line, sci);
			T p = get_root(trees, dir);
			do
			{
				// 去掉SPLIT
				dir = get_next_dir(line, ++sci);
				if (dir != "")
				{
					p = insert(p, dir);
				}
			} while (sci != line.end());	
		}
		sort(trees.begin(), trees.end(), compare);
		for (Trees::const_iterator vi = trees.begin(); vi < trees.end(); 
			vi++)
		{
			output_tree(*vi, 0);
		}
		cout << endl;
	}
	return 0;
}

T get_root(Trees &trees, string root)
{
	Trees::const_iterator tci;
	for (tci = trees.begin(); tci != trees.end(); tci++)
	{
		if ((*tci)->s == root)
		{
			return *tci;
		}
	}
	T new_tree = new TNode(root, nullptr, nullptr);
	trees.push_back(new_tree);
	return new_tree;
}

string get_next_dir(const string &line, string::const_iterator &index) 
{
	string dir;
	while (index != line.end() && *index != SPLIT)
	{
		dir.push_back(*(index++));
	}
	return dir;
}

TNode *insert(TNode * parent, string dir)
{
	TNode *ret = nullptr;
	if (parent == nullptr)
	{
		return ret;
	}
	// 找到合适的插入位置
	else if (parent->lchild == nullptr)
	{
		parent->lchild = new TNode(dir, nullptr, nullptr);
		ret = parent->lchild;
	}
	else if(parent->lchild->s == dir)
	{
		// 重复不插入
		ret = parent->lchild;
	}
	else if (parent->lchild->s > dir)
	{
		// 插入到孩子结点
		TNode *child = parent->lchild, 
			*new_bro = new TNode(child->s, child->lchild, child->rbro);
		child->s = dir;
		child->lchild = nullptr;
		ret = child;
		child->rbro = new_bro;
	}
	else
	{
		// 孩子结点较小，插入到孩子的兄弟中
		TNode * p = parent->lchild;
		while (p->rbro != nullptr && p->rbro->s < dir)
		{
			p = p->rbro;
		}
		if (p->rbro == nullptr || p->rbro->s > dir)
		{
			TNode *new_bro = new TNode(dir, nullptr, p->rbro);
			p->rbro = new_bro;
			ret = new_bro;
		}
		else if (p->rbro->s == dir)
		{
			ret = p->rbro;
		}
	}
	return ret;
}

void output_tree(T tree, int level) 
{
	if (tree == nullptr)
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		cout << LEVEL_GAP;
	}
	cout << tree->s << endl;
	output_tree(tree->lchild, level + 1);
	output_tree(tree->rbro, level);
}

bool compare(T t_l, T t_r)
{
	return t_l->s < t_r->s;
}

