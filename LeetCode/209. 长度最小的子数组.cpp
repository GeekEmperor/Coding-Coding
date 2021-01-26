class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, m = 0, n = nums.size(), t = INT_MAX;
        for (; i < n; ++i) {
            for (; j < n && m < s; ++j)
                m += nums[j];
            if (m < s)
                break;
            if (t > j - i)
                t = j - i;
            m -= nums[i];
        }
        return t == INT_MAX ? 0 : t;
    }
};