class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool cube[9][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                row[i][j] = col[i][j] = cube[i][j] = false;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    int loc = i / 3 * 3 + j / 3;
                    row[i][idx] = col[j][idx] = cube[loc][idx] = true;
                }
        backtrack(board, 0, 0);
    }
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (i >= 9)
            return true;
        if (j >= 9)
            return backtrack(board, i + 1, 0);
        if (board[i][j] != '.')
            return backtrack(board, i, j + 1);
        for (int k = 0; k < 9; ++k) {
            int loc = i / 3 * 3 + j / 3;
            if (!row[i][k] && !col[j][k] && !cube[loc][k]) {
                row[i][k] = col[j][k] = cube[loc][k] = true;
                board[i][j] = k + '1';
                if (backtrack(board, i, j + 1))
                    return true;
                board[i][j] = '.';
                row[i][k] = col[j][k] = cube[loc][k] = false;
            }
        }
        return false;
    }
};