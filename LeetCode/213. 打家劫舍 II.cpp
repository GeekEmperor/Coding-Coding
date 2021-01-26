class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return nums.empty() ? 0 : nums[0];
        int a = 0, b = 0, c = 0, res = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        res = max(res, b);
        a = b = c = 0;
        for (int i = 1; i < n; ++i)
        {
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        res = max(res, b);
        return res;
    }
};