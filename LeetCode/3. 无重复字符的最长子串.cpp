class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[128] = { 0 };
        int n = s.size(), len = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            i = max(i, index[s[j]]);
            len = max(len, j - i + 1);
            index[s[j]] = j + 1;
        }
        return len;
    }
};