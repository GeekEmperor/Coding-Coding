#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<int> c(n + 1), v(n + 1);
		for (int i = 1; i <= n; ++i)
			cin >> c[i] >> v[i];
		vector<int> dp(m + 1, 0);
		vector<vector<int>> item(m + 1);
		for (int i = 1; i <= n; ++i)
			for (int j = m; j >= c[i]; --j)
				if (dp[j] < dp[j - c[i]] + v[i])
				{
					dp[j] = dp[j - c[i]] + v[i];
					item[j] = item[j - c[i]];
					item[j].push_back(i);
				}
		if (!dp[m])
			cout << 0 << endl;
		else
		{
			cout << dp[m] << endl;
			for (int i = 0; i < item[m].size(); ++i)
				cout << item[m][i] << ' ';
			cout << endl;
		}
	}
}