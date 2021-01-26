class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
        recursion(s, 0, s.size() - 1, dp);
        return res;
    }
    
    void recursion(string& s, int a, int b, vector<vector<bool>>& dp) {
        if (a > b) {
            res.emplace_back(temp);
            return;
        }
        int i, j, k;
        for (i = 1; i <= b - a + 1; ++i) {
            if (dp[a][a + i - 1]) {
                temp.emplace_back(s.substr(a, i));
                recursion(s, a + i, b, dp);
                temp.pop_back();
            }
        }
    }
};