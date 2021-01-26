class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (2 * k > n) {
            int a = 0, b = INT_MIN, t;
            for (int i = 0; i < n; ++i) {
                t = a;
                a = max(t, b + prices[i]);
                b = max(b, t - prices[i]);
            }
            return a;
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>{0, INT_MIN}));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
            }
        return dp[n][k][0];
    }
};
