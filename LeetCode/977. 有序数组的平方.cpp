class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = 0, r = A.size() - 1, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(A[mid] >= 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << l;
        vector<int> B(A.begin(), A.begin() + l);
        vector<int> C(A.begin() + l, A.end());
        int m = l, n = A.size() - m;
        int i = m - 1, j = 0, k = 0;
        int b, c;
        while(i >= 0 && j < n) {
            b = B[i] * B[i];
            c = C[j] * C[j];
            if(b < c) {
                A[k++] = b;
                --i;
            }
            else {
                A[k++] = c;
                ++j;
            }
        }
        while(i >= 0) {
            A[k++] = B[i] * B[i];
            --i;
        }
        while(j < n) {
            A[k++] = C[j] * C[j];
            ++j;
        }
        return A;
    }
};