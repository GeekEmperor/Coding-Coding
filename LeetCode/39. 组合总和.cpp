class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty())
            return {};
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
        if (target < 0)
            return;
        for (int j = i; j < candidates.size(); ++j) {
            temp.push_back(candidates[j]);
            backtrack(candidates, target - candidates[j], res, temp, j);
            temp.pop_back();
        }
    }
};