class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            once = ~twice & (once ^ nums[i]);
            twice = ~once & (twice ^ nums[i]);
        }
        return once;
    }
};