class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1, j = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
            --i;
        if (i) {
            while (j > i&& nums[j] <= nums[i - 1])
                --j;
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.end());
    }
};