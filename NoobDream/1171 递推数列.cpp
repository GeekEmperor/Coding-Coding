#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a0, a1, p, q, k;
	while (cin >> a0 >> a1 >> p >> q >> k)
	{
		vector<int> dp(k + 1, 0);
		dp[0] = a0 % 10000;
		dp[1] = a1 % 10000;
		for (int i = 2; i <= k; ++i)
		{
			dp[i] = p * dp[i - 1] + q * dp[i - 2];
			dp[i] %= 10000;
		}
		cout << dp[k] << endl;
	}
}