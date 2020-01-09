class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size(), area = 0;
        vector<vector<int>> width(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == '1') {
                    if (j)
                        width[i][j] = width[i][j - 1] + 1;
                    else
                        width[i][j] = 1;
                    int w = width[i][j];
                    for (int k = i; k >= 0 && width[k][j]; --k) {
                        w = min(w, width[k][j]);
                        area = max(area, w * (i - k + 1));
                    }
                }
        return area;
    }
};