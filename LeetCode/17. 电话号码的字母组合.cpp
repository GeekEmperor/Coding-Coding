class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> map = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res = { "" };
        int n = digits.size(), m, t;
        string s;
        for (int i = 0; i < n; ++i) {
            m = res.size();
            s = map[digits[i] - '2'];
            t = s.size();
            res.resize(t * m);
            for (int j = m; j < t * m; ++j)
                res[j] = res[j - m];
            for (int j = 0; j < t; ++j)
                for (int k = 0; k < m; ++k)
                    res[j * m + k] += s[j];
        }
        return res;
    }
};