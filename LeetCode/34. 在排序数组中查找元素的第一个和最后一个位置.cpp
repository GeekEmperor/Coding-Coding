class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1, -1 };
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (left < nums.size() && nums[left] == target)
            res[0] = left;
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (right >= 0 && nums[right] == target)
            res[1] = right;
        return res;
    }
};