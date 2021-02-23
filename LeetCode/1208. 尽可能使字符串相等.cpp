class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), maxLen = 0, cost = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            cost += abs(s[j] - t[j]);
            while (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                ++i;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};