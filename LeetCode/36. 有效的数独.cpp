class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9], col[9][9], cube[9][9];
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                row[i][j] = col[i][j] = cube[i][j] = false;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int index = board[i][j] - '1';
                int loc = i / 3 * 3 + j / 3;
                if (row[i][index] || col[j][index] || cube[loc][index])
                    return false;
                row[i][index] = col[j][index] = cube[loc][index] = true;
            }
        return true;
    }
};