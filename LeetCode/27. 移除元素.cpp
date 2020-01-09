class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[j--];
                --n;
            }
            else
                ++i;
        }
        return n;
    }
};