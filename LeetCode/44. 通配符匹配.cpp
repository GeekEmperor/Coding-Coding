class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, a = -1, b = -1;
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i;
                ++j;
            }
            else if (p[j] == '*') {
                a = i;
                b = j++;
            }
            else if (a >= 0) {
                i = ++a;
                j = b + 1;
            }
            else
                return false;
        }
        while (j < p.size() && p[j] == '*')
            ++j;
        return j >= p.size();
    }
};