class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
    bool isMatch(string& s, string& p, int i, int j) {
        if (j >= p.size())
            return i >= s.size();
        bool flag = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (p[j + 1] == '*' && flag)
            return isMatch(s, p, i + 1, j) || isMatch(s, p, i, j + 2);
        else if (p[j + 1] == '*')
            return isMatch(s, p, i, j + 2);
        else if (flag)
            return isMatch(s, p, i + 1, j + 1);
        else
            return false;
    }
};