class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> B1(n, 1);
        vector<int> B2(n, 1);
        vector<int> B(n, 1);
        for (int i = 1; i < n; ++i)
            B1[i] = B1[i - 1] * A[i - 1];
        for (int i = n - 2; i >= 0; --i)
            B2[i] = B2[i + 1] * A[i + 1];
        for (int i = 0; i < n; ++i)
            B[i] = B1[i] * B2[i];
        return B;
    }
};