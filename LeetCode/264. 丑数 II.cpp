class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0, x, y, z;
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            x = res[a] * 2;
            y = res[b] * 3;
            z = res[c] * 5;
            res[i] = min(x, min(y, z));
            if (res[i] == x)
                ++a;
            if (res[i] == y)
                ++b;
            if (res[i] == z)
                ++c;
        }
        return res[n - 1];
    }
};