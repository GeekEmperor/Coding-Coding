class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
            int k = j - 1;
            while (k >= i && nums[k] != nums[j])
                --k;
            if (k < i) {
                swap(nums[i], nums[j]);
                permute(nums, res, i + 1);
                swap(nums[i], nums[j]);
            }
        }
    }
};