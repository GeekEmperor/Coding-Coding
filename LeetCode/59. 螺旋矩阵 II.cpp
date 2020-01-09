class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i)
            res[i].resize(n);
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int i = 0, j = 0, k = 1, size = n * n;
        while (1) {
            for (j = left; j <= right; ++j) res[up][j] = k++;
            if (++up > down) break;
            for (i = up; i <= down; ++i) res[i][right] = k++;
            if (--right < left) break;
            for (j = right; j >= left; --j) res[down][j] = k++;
            if (--down < up) break;
            for (i = down; i >= up; --i) res[i][left] = k++;
            if (++left > right) break;
        }
        return res;
    }
};