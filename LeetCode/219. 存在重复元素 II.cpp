class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i]) && i - m[nums[i]] <= k)
                return true;
            else
                m[nums[i]] = i;
        }
        return false;
    }
};