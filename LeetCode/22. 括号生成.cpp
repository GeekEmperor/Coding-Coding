class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
    void generate(vector<string>& res, string s, int l, int r, int n) {
        if (s.size() == 2 * n) {
            res.emplace_back(s);
            return;
        }
        if (l < n)
            generate(res, s + '(', l + 1, r, n);
        if (l > r)
            generate(res, s + ')', l, r + 1, n);
    }
};