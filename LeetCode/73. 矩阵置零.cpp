class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false), col(n, false);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    break;
                }
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                if (matrix[i][j] == 0) {
                    col[j] = true;
                    break;
                }
        for (int i = 0; i < m; ++i)
            if (row[i])
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        for (int j = 0; j < n; ++j)
            if (col[j])
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
    }
};