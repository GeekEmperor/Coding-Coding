#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int num;
	Node* child[26];
	bool flag;
	Node() :num(0), child{ nullptr }{}
};
void add(Node* p, string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{ 
		int j = s[i] - 'a';
		if (!p->child[j])
			p->child[j] = new Node;
		p = p->child[j];
		p->num++;
	}
}
void del(Node* p)
{
	if (!p)
		return;
	for (int i = 0; i < 26; ++i)
		del(p->child[i]);
	delete p;
}
int find(Node* p, string& s)
{
	for (int i = 0; i < s.size() && p; ++i)
	{
		int j = s[i] - 'a';
		p = p->child[j];
	}
	return p ? p->num : 0;
}
int main()
{
	int n;
	cin >> n;
	Node* root = new Node;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		add(root, s);
	}
	int m;
	cin >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		cout << find(root, s) << endl;
	}
	del(root);
	return 0;
}
