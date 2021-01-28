class Solution {
public:
    int GetUglyNumber_Solution(int n) {
        if (!n)
            return 0;
        int a = 0, b = 0, c = 0, x, y, z, res;
        int* dp = new int[n];
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            x = dp[a] * 2, y = dp[b] * 3, z = dp[c] * 5;
            dp[i] = min(x, min(y, z));
            if (dp[i] == x)
                ++a;
            if (dp[i] == y)
                ++b;
            if (dp[i] == z)
                ++c;
        }
        res = dp[n - 1];
        delete[] dp;
        return res;
    }
};