class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), mask = 0, a = 0, b = 0;
        for (int i = 0; i < n; ++i)
            mask ^= nums[i];
        mask &= ~(mask - 1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] & mask)
                a ^= nums[i];
            else
                b ^= nums[i];
        };
        return {a, b};
    }
};
