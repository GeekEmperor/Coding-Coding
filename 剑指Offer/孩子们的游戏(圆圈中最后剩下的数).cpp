class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (!n)
            return -1;
        int res = 0;
        for (int i = 2; i <= n ;++i)
            res = (res + m) % i;
        return res;
    }
};