#include <iostream>
using namespace std;
struct Node
{
	char c;
	Node* l;
	Node* r;
	Node(char c)
	{
		this->c = c;
		this->l = this->r = nullptr;
	}
};
int leaf = 0;
Node* construct()
{
	char c;
	cin >> c;
	if (c == '0')
		return nullptr;
	Node* node = new Node(c);
	node->l = construct();
	node->r = construct();
	if (!node->l && !node->r)
		++leaf;
	return node;
}
void preorder(Node* node)
{
	if (!node)
		return;
	cout << node->c << ' ';
	preorder(node->l);
	preorder(node->r);
}
void inorder(Node* node)
{
	if (!node)
		return;
	inorder(node->l);
	cout << node->c << ' ';
	inorder(node->r);
}
void postorder(Node* node)
{
	if (!node)
		return;
	postorder(node->l);
	postorder(node->r);
	cout << node->c << ' ';
}
void count(Node* node)
{
	cout << leaf;
}
void destruct(Node* node)
{
	if (!node)
		return;
	destruct(node->l);
	destruct(node->r);
	delete node;
}
int main()
{
	Node* tree = construct();
	void (*ptrs[5])(Node*) = { preorder, inorder, postorder, count, destruct };
	for (auto ptr : ptrs)
	{
		ptr(tree);
		cout << endl;
	}
}