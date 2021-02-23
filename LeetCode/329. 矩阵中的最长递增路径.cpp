class Solution {
private:
    int m, n;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    inline bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& len, int i, int j) {
        if (len[i][j])
            return len[i][j];
        for (int k = 0; k < 4; ++k) {
            int u = i + dirs[k][0], v = j + dirs[k][1];
            if (valid(u, v) && matrix[u][v] > matrix[i][j] && dfs(matrix, len, u, v) >= len[i][j])
                len[i][j] = len[u][v] + 1;
        }
        return len[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> len(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!len[i][j] && dfs(matrix, len, i, j) > ans)
                    ans = len[i][j];
        return ans + 1;
    }
};