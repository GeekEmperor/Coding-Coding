class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), i, j, temp;
        vector<int> dp(n + 1, 0);
        for (i = 0; i < n; ++i) {
            temp = 0;
            for (j = 0; j < i; ++j)
                if (nums[i] > nums[j] && temp < dp[j])
                    temp = dp[j];
            dp[i] = temp + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
