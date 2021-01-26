class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(), i = 0, j = (n + 1) / 2, k = n;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        for (; i < n; ++i)
            nums[i] = (i & 1) ? temp[--k] : temp[--j];
    }
};