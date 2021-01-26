class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int j = abs(nums[i]) - 1;
            nums[j] = -abs(nums[j]);
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                res.emplace_back(i + 1);
        return res;
    }
};