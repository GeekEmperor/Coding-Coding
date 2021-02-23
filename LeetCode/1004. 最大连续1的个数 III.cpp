class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), ans = 0, count = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (!A[i] && ++count > K) {
                for (; j < i && A[j]; ++j);
                ++j;
                --count;
            }
            if (i - j + 1 > ans)
                ans = i - j + 1;
        }
        return ans;
    }
};