class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), big = 1, small = 1, ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0)
                swap(big, small);    
            big = max(nums[i], big * nums[i]);
            small = min(nums[i], small * nums[i]);
            ans = max(ans, big);
        }
        return ans;
    }
};
