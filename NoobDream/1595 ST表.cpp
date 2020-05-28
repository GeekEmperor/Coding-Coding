#include <iostream>
#include <algorithm>
using namespace std;
int st[100000][15];
int main()
{
	int n, m, l, r, len;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &st[i][0]);
	for (int j = 1; (1 << j) <= n; ++j)
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &l, &r);
		--l, --r;
		len = r - l + 1;
		int j = 0;
		while (len != 1)
		{
			len >>= 1;
			++j;
		}
		printf("%d\n", max(st[l][j], st[r - (1 << j) + 1][j]));
	}
}