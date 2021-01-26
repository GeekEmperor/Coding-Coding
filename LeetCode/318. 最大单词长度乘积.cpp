class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0, i, j, t;
        vector<int> count(n);
        for (i = 0; i < n; ++i)
            for (j = 0; j < words[i].size(); ++j)
                count[i] |= (1 << (words[i][j] - 'a'));
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j) {
                if (!(count[i] & count[j])) {
                    t = words[i].size() * words[j].size();
                    res = max(res, t);
                }
            }
        return res;
    }
};
