#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m, u, v;
	while (cin >> n >> m)
	{
		vector<int> a(n + 1, 0);
		while (m--)
		{
			cin >> u >> v;
			while (a[v])
				v = a[v];
			a[u] = v;
		}
		int count = 0;
		for (int i = 1; i <= n; ++i)
			if (!a[i])
				++count;
		cout << count - 1 << endl;
	}
}