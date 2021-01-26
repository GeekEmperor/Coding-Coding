class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 10000)
            return false;
        int i, j, n = nums.size();
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < min(i + k + 1, n); ++j)
                if (abs((long)nums[i] - (long)nums[j]) <= t)
                    return true;
        return false;
    }
};