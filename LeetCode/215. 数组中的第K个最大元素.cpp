class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return partition(nums, n - k + 1, 0, n - 1);
    }
    int partition(vector<int>& nums, int k, int s, int e) {
        if (s >= e)
            return nums[e];
        int pivot = nums[s], i = s, j = e;
        while (i < j) {
            while (i < j && nums[j] > pivot)
                --j;
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot)
                ++i;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        if (i - s == k - 1)
            return nums[i];
        else if (i - s < k - 1)
            return partition(nums, k - 1 - i + s, i + 1, e);
        else
            return partition(nums, k, s, i - 1);
    }
};
