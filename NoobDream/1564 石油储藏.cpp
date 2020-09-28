#include <iostream>
#include <vector>
#include <string>
using namespace std;
int m, n;
int dir[8][2] = { -1, 0, 0, -1, 1, 0, 0, 1, -1, -1, -1, 1, 1, -1, 1, 1};
void dfs(vector<string>& matrix, int i, int j)
{
	if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == '*')
		return;
	matrix[i][j] = '*';
	for (int k = 0; k < 8; ++k)
		dfs(matrix, i + dir[k][0], j + dir[k][1]);
}
int main()
{
	while (cin >> m >> n && (m || n))
	{
		vector<string> matrix(m);
		for (int i = 0; i < m; ++i)
			cin >> matrix[i];
		int count = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (matrix[i][j] == '@')
				{
					++count;
					dfs(matrix, i, j);
				}
		cout << count << endl;
	}
}