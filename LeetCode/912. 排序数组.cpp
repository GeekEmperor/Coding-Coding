class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        swap(nums[l], nums[rand() % (r - l + 1) + l]);
        int pivot = nums[l], start = l, end = r;
        while (l < r) {
            while (l < r && nums[r] > pivot)
                --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot)
                ++l;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        quicksort(nums, start, r - 1);
        quicksort(nums, l + 1, end);
    }
};
