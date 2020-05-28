#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n, m, x, y, z;
	scanf("%d%d", &n, &m);
	vector<vector<pair<int, int>>> graph(n + 1);
	while (m--)
	{
		scanf("%d%d%d", &x, &y, &z);
		graph[x].emplace_back(z, y);
		graph[y].emplace_back(z, x);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (const auto& p : graph[1])
		pq.push(p);
	vector<bool> visit(n + 1, false);
	visit[1] = true;
	int length = 0, count = 1;
	while (count < n && !pq.empty())
	{
		auto p = pq.top();
		pq.pop();
		if (visit[p.second])
			continue;
		visit[p.second] = true;
		++count;
		length += p.first;
		for (const auto& q : graph[p.second])
			if (!visit[q.second])
				pq.push(q);
	}
	if (count < n)
		printf("orz");
	else
		printf("%d", length);
}