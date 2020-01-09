class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums, res, 0);
        return res;
    }
    void permute(vector<int>& nums, vector<vector<int>>& res, int i) {
        if (i >= nums.size()) {
            res.emplace_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            permute(nums, res, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};