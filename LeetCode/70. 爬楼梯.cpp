class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 1;
        for (int i = 2; i <= n; ++i) {
            c += a;
            a = b;
            b = c;
        }
        return b;
    }
};