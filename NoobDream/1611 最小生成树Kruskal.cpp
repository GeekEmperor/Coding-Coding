#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
	int x, y, z;
	Edge(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
	bool operator<(const Edge& e) { return z < e.z; }
};
class UFSet
{
private:
	vector<int> v;
public:
	UFSet(int n) : v(n + 1, 0) {}
	int Find(int x)
	{
		while (v[x] > 0)
			x = v[x];
		return x;
	}
	void Union(int x, int y)
	{
		v[x] = y;
	}
};
int main()
{
	int n, m, x, y, z, a, b;
	scanf("%d%d", &n, &m);
	vector<Edge> edges;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		edges.emplace_back(x, y, z);
	}
	sort(edges.begin(), edges.end());
	int length = 0, count = 1;
	UFSet uf(n);
	for (int i = 0; i < m; ++i)
	{
		a = uf.Find(edges[i].x);
		b = uf.Find(edges[i].y);
		if (a != b)
		{
			uf.Union(a, b);
			++count;
			length += edges[i].z;
		}
	}
	if (count < n)
		printf("orz");
	else
		printf("%d", length);
}