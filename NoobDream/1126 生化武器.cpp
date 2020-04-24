#include <iostream>
#include <string>
#include <vector>
using namespace std;
void dfs(vector<string>& matrix, int i, int j, int t)
{
	matrix[i][j] = '#';
	if (!t)
		return;
	if (i - 1 >= 0 && j < matrix[i - 1].size() && matrix[i - 1][j] != 'X')
		dfs(matrix, i - 1, j, t - 1);
	if (i + 1 < matrix.size() && j < matrix[i + 1].size() && matrix[i + 1][j] != 'X')
		dfs(matrix, i + 1, j, t - 1);
	if (j - 1 >= 0 && matrix[i][j - 1] != 'X')
		dfs(matrix, i, j - 1, t - 1);
	if (j + 1 < matrix[i].size() && matrix[i][j + 1] != 'X')
		dfs(matrix, i, j + 1, t - 1);
}
int main()
{
	int n, m, t;
	while (cin >> n >> m >> t)
	{
		vector<string> matrix(n);
		for (int i = 0; i < n; ++i)
			cin >> matrix[i];
		int i, j;
		for (i = 0; i < n; ++i)
			for (j = 0; j < matrix[i].size(); ++j)
				if (matrix[i][j] == '*')
					dfs(matrix, i, j, t);
		for (int i = 0; i < n; ++i)
			cout << matrix[i] << endl;
		cout << endl;
	}
}