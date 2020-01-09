class Solution {
public:
    vector<int> grayCode(int n) {
        int m = 1 << n;
        vector<int> res(m);
        for (int i = 0; i < m; ++i)
            res[i] = ((i >> 1) ^ i);
        return res;
    }
};