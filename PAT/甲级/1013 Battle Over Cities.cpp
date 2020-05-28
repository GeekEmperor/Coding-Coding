#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n, m, k, u, v;
	scanf("%d%d%d", &n, &m, &k);
	vector<vector<int>> graph(n + 1);
	while (m--)
	{
		scanf("%d%d", &u, &v);
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	while (k--)
	{
		scanf("%d", &u);
		int count = -1;
		vector<bool> visit(n + 1, false);
		for (int i = 1; i <= n; ++i)
		{
			if (i != u && !visit[i])
			{
				++count;
				stack<int> s;
				s.push(i);
				visit[i] = true;
				while (!s.empty())
				{
					v = s.top();
					s.pop();
					for (int j : graph[v])
						if (j != u && !visit[j])
						{
							s.push(j);
							visit[j] = true;
						}
				}
			}
		}
		cout << count << endl;
	}
}