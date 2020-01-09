class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return (high >= 0 && nums[high] > target) ? high : low;
    }
};