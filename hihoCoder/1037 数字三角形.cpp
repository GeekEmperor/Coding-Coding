#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; ++i)
	{
		matrix[i].resize(i + 1);
		for (int j = 0; j < i + 1; ++j)
			cin >> matrix[i][j];
	}
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i + 1; ++j)
		{
			if (j == 0)
				matrix[i][j] += matrix[i - 1][j];
			else if (j == i)
				matrix[i][j] += matrix[i - 1][j - 1];
			else
				matrix[i][j] += max(matrix[i - 1][j - 1], matrix[i - 1][j]);
		}
	cout << *max_element(matrix[n - 1].begin(), matrix[n - 1].end());
	return 0;
}
