#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, w;
	while (cin >> n >> w)
	{
		vector<int> W(n), V(n);
		for (int i = 0; i < n; ++i)
			cin >> W[i] >> V[i];
		vector<int> dp(w + 1, 0);
		for (int i = 0; i < n; ++i)
			for (int j = W[i]; j <= w; ++j)
				dp[j] = max(dp[j - W[i]] + V[i], dp[j]);
		cout << dp[w] << endl;
	}
}