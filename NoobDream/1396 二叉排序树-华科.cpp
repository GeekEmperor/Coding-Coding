#include <iostream>
using namespace std;
struct Node
{
	int d;
	Node* l;
	Node* r;
	Node(int d)
	{
		this->d = d;
		this->l = this->r = nullptr;
	}
};
int insert(Node* node, int x)
{
	if (node->d < x)
	{
		if (node->l)
			return insert(node->l, x);
		else
		{
			node->l = new Node(x);
			return node->d;
		}
	}
	else
	{
		if (node->r)
			return insert(node->r, x);
		else
		{
			node->r = new Node(x);
			return node->d;
		}
	}
}
int main()
{
	Node* tree = new Node(-1);
	int n, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		cout << insert(tree, x) << endl;
	}
}