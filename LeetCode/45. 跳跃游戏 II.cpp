class Solution {
public:
    int jump(vector<int>& nums) {
        int i, j = 0, k = 0, n = nums.size() - 1, res = 0;
        for (i = 0; i < n; ++i)
        {
            k = max(k, i + nums[i]);
            if (i == j)
            {
                ++res;
                j = k;
                if (j >= n)
                    break;
            }
        }
        return res;
    }
};