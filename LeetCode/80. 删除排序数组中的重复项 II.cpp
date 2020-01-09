class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        for (; j < n; ++j) {
            if (i < 2 || nums[j] != nums[i - 2])
                nums[i++] = nums[j];
        }
        return i;
    }
};