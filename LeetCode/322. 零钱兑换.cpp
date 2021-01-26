class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 1; j <= amount; ++j)
                if (j >= coins[i])
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};