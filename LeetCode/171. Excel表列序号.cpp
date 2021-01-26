class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res *= 26;
            res += s[i] - 64;
        }
        return res;
    }
};
