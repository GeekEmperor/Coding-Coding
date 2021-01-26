class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        bitset<5001> bits(1);
        for (int m : nums)
            bits |= bits << m;
        return ~sum & 1 && bits[sum >> 1];
    }
};