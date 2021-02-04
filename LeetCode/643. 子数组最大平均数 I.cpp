class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), ans, sum;
        ans = sum = accumulate(nums.begin(), nums.begin() + k, 0);
        for (int i = k; i < n; ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            if (sum > ans)
                ans = sum;
        }
        return (double)ans / k;
    }
};