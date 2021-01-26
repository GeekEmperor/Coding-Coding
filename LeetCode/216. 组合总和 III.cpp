class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(k, n, res, temp, 1);
        return res;
    }
    void backtrack(int k, int n, vector<vector<int>>& res, vector<int>& temp, int i) {
        if (!k && !n) {
            res.emplace_back(temp);
            return;
        }
        if (k < 0 || n < 0 || i > 9)
            return;
        for (int j = i; j <= 9; ++j) {
            temp.push_back(j);
            backtrack(k - 1, n - j, res, temp, j + 1);
            temp.pop_back();
        }
    }
};