class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        int fact = 1;
        for (int i = 1; i <= n; ++i)
            fact *= i;
        --k;
        for (int i = n; i >= 1; --i) {
            fact /= i;
            int j = k / fact;
            k %= fact;
            res += nums[j];
            nums.erase(j, 1);
        }
        return res;
    }
};