class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty())
            return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates, target, res, temp, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int i) {
        if (!target) {
            res.emplace_back(temp);
            return;
        }
        if (target < 0 || i > candidates.size())
            return;
        for (int j = i; j < candidates.size(); ++j) {
            if (j > i&& candidates[j] == candidates[j - 1])
                continue;
            temp.push_back(candidates[j]);
            backtrack(candidates, target - candidates[j], res, temp, j + 1);
            temp.pop_back();
        }
    }
};