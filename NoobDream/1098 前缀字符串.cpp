#include <iostream>
#include <string>
using namespace std;
struct Node
{
	bool w = false;
	Node* child[26] = { nullptr };
};
Node* construct(int n)
{
	string s;
	Node* root = new Node;
	while (n--)
	{
		cin >> s;
		Node* cur = root;
		for (char c : s)
		{
			Node*& next = cur->child[c - 'a'];
			if (!next)
				next = new Node;
			cur = next;
		}
		cur->w = true;
	}
	return root;
}
int size(Node* node)
{
	bool leaf = true;
	int count = 0;
	for (Node* child : node->child)
		if (child)
		{
			leaf = false;
			count += size(child);
		}
	return leaf ? 1 : count;
}
void destruct(Node* node)
{
	for (Node* child : node->child)
		if (child)
			destruct(child);
	delete node;
}
int main()
{
	int n;
	string s;
	while (cin >> n && n)
	{
		Node* root = construct(n);
		cout << size(root) << endl;
		destruct(root);
	}
}