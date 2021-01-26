class Solution {
public:
    int m, n;
    inline int live(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;
        return board[i][j] == 1 || board[i][j] == 2;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int count = live(board, i - 1, j - 1) + live(board, i - 1, j) + live(board, i - 1, j + 1) + live(board, i, j - 1) + live(board, i, j + 1) + live(board, i + 1, j - 1) + live(board, i + 1, j) + live(board, i + 1, j + 1);
                if (board[i][j]) {
                    if (count < 2 || count > 3)
                        board[i][j] = 2;
                }
                else {
                    if (count == 3)
                        board[i][j] = 3;
                }
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] &= 1;
    }
};