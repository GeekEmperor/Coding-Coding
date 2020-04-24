#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(vector<int>& k, int a, int b)
{
	int n = k.size(), count = 0;
	vector<bool> v(n, false);
	v[a] = true;
	queue<int> q;
	q.push(a);
	while (!q.empty())
	{
		++count;
		int size = q.size();
		while (size--)
		{
			int c = q.front();
			int up = c + k[c], down = c - k[c];
			q.pop();
			if (up == b || down == b)
				return count;
			if (up < n && !v[up])
				q.push(c + k[c]), v[up] = true;
			if (down >= 0 && !v[down])
				q.push(c - k[c]), v[down] = false;
		}
	}
	return -1;
}
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	--a, --b;
	vector<int> k(n);
	for (int i = 0; i < n; ++i)
		cin >> k[i];
	cout << bfs(k, a, b);
}