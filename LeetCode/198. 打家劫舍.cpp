class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < nums.size(); ++i) {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return c;
    }
};
