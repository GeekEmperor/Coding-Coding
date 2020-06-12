#include <iostream>
using namespace std;
struct Node
{
	int num;
	Node* next;
	Node(int n)
	{
		num = n;
		next = nullptr;
	}
};
int main()
{
	int n, s, m;
	while (cin >> n >> s >> m)
	{
		if (!n && !s && !m)
			break;
		Node head(0);
		Node* p = &head, * q;
		for (int i = 1; i <= n; ++i)
		{
			q = new Node(i);
			p->next = q;
			p = q;
		}
		p = head.next;
		q->next = p;
		p = &head, q = head.next;
		for (int i = 1; i < s; ++i)
		{
			p = p->next;
			q = q->next;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				p = p->next;
				q = q->next;
			}
			p->next = q->next;
			cout << q->num << ',';
			delete q;
			q = p->next;
		}
		cout << q->num << endl;
		delete q;
	}
}