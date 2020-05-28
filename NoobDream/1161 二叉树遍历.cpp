#include <iostream>
using namespace std;
struct Node
{
	char c;
	Node* l, * r;
	Node(char c)
	{
		this->c = c;
		l = r = nullptr;
	}
};
struct Tree
{
	Node* root;
	Node* construct(char*& s)
	{
		if (*s == '\0')
			return nullptr;
		if (*s == '#')
		{
			++s;
			return nullptr;
		}
		Node* node = new Node(*s);
		++s;
		node->l = construct(s);
		node->r = construct(s);
		return node;
	}
	void destruct(Node* node)
	{
		if (!node)
			return;
		destruct(node->l);
		destruct(node->r);
		delete node;
	}
	void inorder(Node* node)
	{
		if (!node)
			return;
		inorder(node->l);
		putchar(node->c);
		putchar(' ');
		inorder(node->r);
	}
	Tree(char* s)
	{
		root = construct(s);
	}
	~Tree()
	{
		destruct(root);
	}
	void inorder()
	{
		inorder(root);
	}
};
int main()
{
	char s[101];
	while (cin >> s)
	{
		Tree tree(s);
		tree.inorder();
		putchar('\n');
	}
}