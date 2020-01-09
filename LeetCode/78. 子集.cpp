class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, temp, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int i) {
        if (i >= nums.size()) {
            res.emplace_back(temp);
            return;
        }
        dfs(res, temp, nums, i + 1);
        temp.push_back(nums[i]);
        dfs(res, temp, nums, i + 1);
        temp.pop_back();
    }
};