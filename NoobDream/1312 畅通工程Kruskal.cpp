#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	int x, y, w;
	bool operator<(const Node& node) { return w < node.w; }
};
int find(int* fa, int x)
{
	if (!fa[x])
		return x;
	fa[x] = find(fa, fa[x]);
	return fa[x];
}
int main()
{
	int n, m;
	while (cin >> m >> n && m)
	{
		Node* edge = new Node[m];
		for (int i = 0; i < m; ++i)
			cin >> edge[i].x >> edge[i].y >> edge[i].w;
		sort(edge, edge + m);
		int* fa = new int[n + 1];
		for (int i = 0; i <= n; ++i)
			fa[i] = 0;
		int count = 1, len = 0;
		for (int i = 0; i < m; ++i)
		{
			int x = find(fa, edge[i].x), y = find(fa, edge[i].y);
			if (x != y)
			{
				fa[x] = y;
				++count;
				len += edge[i].w;
			}
		}
		delete[] fa;
		delete[] edge;
		if (count == n)
			cout << len << endl;
		else
			cout << "?\n";
	}
}