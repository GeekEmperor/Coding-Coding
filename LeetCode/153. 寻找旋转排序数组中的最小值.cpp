class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot = nums[0], left = 1, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if(nums[mid] > pivot)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left < nums.size() ? nums[left] : pivot;
    }
};
