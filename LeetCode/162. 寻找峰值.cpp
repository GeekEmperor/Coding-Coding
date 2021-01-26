

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int left = 1, right = nums.size() - 2, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid - 1;
            else if (nums[mid] >= nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
};
