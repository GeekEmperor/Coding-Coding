class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n)
            return uniquePaths(n, m);
        long res = 1;
        for (int i = 1; i < n; ++i) {
            res *= (m - 1 + i);
            res /= i;
        }
        return res;
    }
};