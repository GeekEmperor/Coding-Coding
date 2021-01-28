class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, part = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        for (int i = 0; i < n; ++i) {
            if (sum - nums[i] == part * 2)
                return i;
            part += nums[i];
        }
        return -1;
    }
};