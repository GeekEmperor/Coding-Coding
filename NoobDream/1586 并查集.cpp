#include <iostream>
using namespace std;
class UFSet
{
private:
	int* v;
public:
	UFSet(int n)
	{
		v = new int[n + 1];
		for (int i = 0; i <= n; ++i)
			v[i] = i;
	}
	~UFSet()
	{
		delete[] v;
	}
	int Find(int x)
	{
		while (v[x] != x)
			x = v[x];
		return x;
	}
	void Union(int x, int y)
	{
		x = Find(x), y = Find(y);
		v[y] = x;
	}
};
int main()
{
	int n, m, x, y, z;
	scanf("%d%d", &n, &m);
	UFSet ufset(n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &z, &x, &y);
		if (z == 1)
			ufset.Union(x, y);
		else if (ufset.Find(x) == ufset.Find(y))
			printf("Y\n");
		else
			printf("N\n");
	}
}