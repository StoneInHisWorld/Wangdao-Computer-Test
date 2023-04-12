//����
//����һ��·����Ʃ�磺
//a\b\c
//a\d\e
//b\cst
//d\
//�����Щ·�����̺���Ŀ¼�ṹ������������Ŀ¼ֱ�����ڸ�Ŀ¼���棬���ȸ�Ŀ¼�����ַ������������ո񣬾���������
//a
//b
//c
//d
//e
//b
//cst
//d
//ע��ͬһ������Ҫ����ĸ˳�����У������ҡ�
//����������
//ÿ�����԰�����һ��Ϊһ��������n��n <= 10����ʾ��n��·������nΪ0ʱ�����Խ�������������n�У�ÿ����һ���ִ���ʾһ��·��������С��50��
//���������
//���Ŀ¼�ṹ��ÿһ�������������������һ�����С�
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
			// ��ȡ��Ŀ¼
			string::const_iterator sci = line.begin();
			string dir = get_next_dir(line, sci);
			T p = get_root(trees, dir);
			do
			{
				// ȥ��SPLIT
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
	// �ҵ����ʵĲ���λ��
	else if (parent->lchild == nullptr)
	{
		parent->lchild = new TNode(dir, nullptr, nullptr);
		ret = parent->lchild;
	}
	else if(parent->lchild->s == dir)
	{
		// �ظ�������
		ret = parent->lchild;
	}
	else if (parent->lchild->s > dir)
	{
		// ���뵽���ӽ��
		TNode *child = parent->lchild, 
			*new_bro = new TNode(child->s, child->lchild, child->rbro);
		child->s = dir;
		child->lchild = nullptr;
		ret = child;
		child->rbro = new_bro;
	}
	else
	{
		// ���ӽ���С�����뵽���ӵ��ֵ���
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

