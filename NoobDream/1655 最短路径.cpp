#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int floyd(vector<vector<int>>& matrix)
{
	int n = matrix.size() - 1;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
	return matrix[1][n];
}
int main()
{
	int t, n, m, k, x, y, z, l;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX >> 1));
		vector<vector<int>> edge(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y >> z;
			edge[i] = { x, y, z };
			matrix[x][y] = matrix[y][x] = min(matrix[x][y], z);
		}
		cout << floyd(matrix) << endl;
		for (int i = 0; i < k; ++i)
		{
			cin >> l;
			--l;
			edge[l][2] = INT_MAX >> 1;
		}
		matrix = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX >> 1));
		for (int i = 0; i < m; ++i)
		{
			x = edge[i][0], y = edge[i][1], z = edge[i][2];
			matrix[x][y] = matrix[y][x] = min(matrix[x][y], z);
		}
		cout << floyd(matrix) << endl;
	}
}