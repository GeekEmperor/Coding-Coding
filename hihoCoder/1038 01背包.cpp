#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> need(n), value(n);
	for (int i = 0; i < n; ++i)
		cin >> need[i] >> value[i];
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = m; j >= 0; --j)
			if (j >= need[i])
				dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
	cout << dp[m];
	return 0;
}
