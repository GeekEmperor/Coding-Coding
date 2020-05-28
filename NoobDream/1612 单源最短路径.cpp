#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
	int n, m, s, u, v, w;
	scanf("%d%d%d", &n, &m, &s);
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		graph[u].emplace_back(v, w);
	}
	vector<bool> visit(n + 1, false);
	vector<int> dis(n + 1, INT_MAX);
	dis[s] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int idx = 0;
		for (int i = 1; i <= n; ++i)
			if (!visit[i] && dis[i] < dis[idx])
				idx = i;
		if (!idx)
			break;
		visit[idx] = true;
		for (const auto& p : graph[idx])
			if (dis[idx] + p.second < dis[p.first])
				dis[p.first] = dis[idx] + p.second;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", dis[i]);
}