class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n);
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            cut[i] = n - i - 1;
            for (int j = i; j < n; ++j)
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    cut[i] = (j == n - 1) ? 0 : min(cut[i], cut[j + 1] + 1);
                }
        }
        return cut[0];
    }
};
