class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), t = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if (s == target)
                    return target;
                else if (s > target)
                    --r;
                else
                    ++l;
                if (abs(s - target) < abs(t - target))
                    t = s;
            }
        }
        return t;
    }
};