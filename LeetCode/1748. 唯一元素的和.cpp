class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0, counts[101] = {};
        for (int n : nums)
            ++counts[n];
        for (int i = 1; i < 101; ++i)
            if (counts[i] == 1)
                ans += i;
        return ans;
    }
};