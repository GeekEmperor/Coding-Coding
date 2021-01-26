class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int life = 0, index = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[index] != nums[i])
                --life;
            else
                ++life;
            if (life <= 0) {
                index = i + 1;
                life = 0;
            }
        }
        return nums[index];
    }
};
