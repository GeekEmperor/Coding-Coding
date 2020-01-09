class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (backtrack(board, word, i, j, 0))
                    return true;
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k >= word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        bool flag = backtrack(board, word, i - 1, j, k + 1) || backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i, j - 1, k + 1) || backtrack(board, word, i, j + 1, k + 1);
        board[i][j] = c;
        return flag;
    }
};