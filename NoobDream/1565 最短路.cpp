#include <iostream>
#include <vector>
using namespace std;
int main()
{
	const int MAX = 0x3f3f3f3f;
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		vector<vector<int>> graph(n + 1, vector<int>(n + 1, MAX));
		int a, b, c;
		while (m--)
		{
			cin >> a >> b >> c;
			if (c < graph[a][b])
				graph[a][b] = graph[b][a] = c;
		}
		vector<int> len(n + 1, MAX);
		vector<bool> visit(n + 1, false);
		len[1] = 0;
		int u = 1;
		while (u != n)
		{
			visit[u] = true;
			for (int i = 1; i <= n; ++i)
				if (!visit[i] && len[u] + graph[u][i] < len[i])
					len[i] = len[u] + graph[u][i];
			u = 0;
			for (int i = 1; i <= n; ++i)
				if (!visit[i] && len[i] < len[u])
					u = i;
		}
		cout << len[n] << endl;
	}
}