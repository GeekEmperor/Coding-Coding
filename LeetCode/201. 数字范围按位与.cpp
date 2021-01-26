class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++x;
        }
        return m << x;
    }
};
