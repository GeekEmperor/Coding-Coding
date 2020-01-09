class Solution {
public:
    vector<bool> col;
    vector<bool> a;
    vector<bool> b;
    int totalNQueens(int n) {
        col.resize(n, false);
        a.resize(2 * n - 1, false);
        b.resize(2 * n - 1, false);
        int total = backtrack(n, 0);
        return total;
    }
    int backtrack(int n, int i) {
        if (i >= n) {
            return 1;
        }
        int total = 0;
        for (int j = 0; j < n; ++j) {
            if (col[j] || a[i - j + n - 1] || b[i + j])
                continue;
            col[j] = a[i - j + n - 1] = b[i + j] = true;
            total += backtrack(n, i + 1);
            col[j] = a[i - j + n - 1] = b[i + j] = false;
        }
        return total;
    }
};