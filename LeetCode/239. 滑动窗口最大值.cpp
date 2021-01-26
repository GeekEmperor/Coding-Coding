class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = 0; i <= n - k; ++i)
            ans[i] = *max_element(nums.begin() + i, nums.begin() + i + k);
        return ans;
    }
};