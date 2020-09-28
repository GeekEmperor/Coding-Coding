#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int bfs(vector<string>& matrix)
{
	int h = matrix.size(), w = matrix[0].size(), sx, sy;
	for (int i = 0; i < h; ++i)
		if (matrix[i].find('S') != -1)
			sx = i, sy = matrix[i].find('S');
	vector<pair<int, int>> dir = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	matrix[sx][sy] = '#';
	int level = 0;
	while (!q.empty())
	{
		++level;
		int size = q.size();
		while (size--)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int ni = cur.first + dir[i].first, nj = cur.second + dir[i].second;
				if (ni < 0 || ni >= h || nj < 0 || nj >= w || matrix[ni][nj] == '#')
					continue;
				if (matrix[ni][nj] == 'E')
					return level;
				else
				{
					matrix[ni][nj] = '#';
					q.push(make_pair(ni, nj));
				}
			}
		}
	}
	return -1;
}
int main()
{
	int h, w;
	while (cin >> h >> w && (h || w))
	{
		vector<string> matrix(h);
		for (int i = 0; i < h; ++i)
			cin >> matrix[i];
		cout << bfs(matrix) << endl;
	}
}