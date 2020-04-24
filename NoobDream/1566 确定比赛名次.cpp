#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<int> degree(n + 1, 0);
	while (m--)
	{
		cin >> a >> b;
		graph[b].emplace_back(a);
		++degree[a];
	}
	for (int i = 1; i <= n; ++i)
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	vector<int> ans;
	queue<int> q;
	for (int i = n; i > 0; --i)
		if (!degree[i])
			q.push(i);
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		ans.emplace_back(i);
		for (int j : graph[i])
			if (--degree[j] <= 0)
				q.push(j);
	}
	cout << ans[n - 1];
	for (int i = n - 2; i >= 0; --i)
		cout << ' ' << ans[i];
}