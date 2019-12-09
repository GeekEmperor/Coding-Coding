class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size(), i = 1, j;
        for (int j = 1; j < n; ++j)
            if (nums[j] != nums[j - 1])
                nums[i++] = nums[j];
        return i;
    }
};