#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		vector<int> dp(m + 1, 200);
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = m; j >= v[i]; --j)
				dp[j] = min(dp[j], dp[j - v[i]] + 1);
		cout << (dp[m] == 200 ? 0 : dp[m]) << endl;
	}
}