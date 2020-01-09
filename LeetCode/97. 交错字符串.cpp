class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        vector<bool> dp(n2 + 1, false);
        dp[0] = 1;
        for (int j = 1; j <= n2; ++j)
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= n1; ++i) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n2; ++j)
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1]
                || dp[j - 1] && s2[j - 1] == s3[i + j - 1];
        }
        return dp[n2];
    }
};