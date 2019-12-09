class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, k, n = s.size(), b = 0, e = -1;
        for (i = 0; i < n; ++i) {
            j = k = i;
            while (j >= 0 && k < n && s[j] == s[k])
                --j, ++k;
            if (e - b + 1 < k - j - 1) {
                b = j + 1;
                e = k - 1;
            }
            j = i, k = i + 1;
            while (j >= 0 && k < n && s[j] == s[k])
                --j, ++k;
            if (e - b + 1 < k - j - 1) {
                b = j + 1;
                e = k - 1;
            }
        }
        return s.substr(b, e - b + 1);
    }
};