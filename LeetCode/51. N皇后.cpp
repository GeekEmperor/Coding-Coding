class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> col;
    vector<bool> a;
    vector<bool> b;

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        col.resize(n, false);
        a.resize(2 * n - 1, false);
        b.resize(2 * n - 1, false);
        backtrack(n, 0);
        return res;
    }

    void backtrack(int n, int i) {
        if (i >= n) {
            res.emplace_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] || a[i - j + n - 1] || b[i + j])
                continue;
            board[i][j] = 'Q';
            col[j] = a[i - j + n - 1] = b[i + j] = true;
            backtrack(n, i + 1);
            col[j] = a[i - j + n - 1] = b[i + j] = false;
            board[i][j] = '.';
        }
    }
};