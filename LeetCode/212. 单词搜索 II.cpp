class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int i, j, k;
        vector<string> res;
        for (k = 0; k < words.size(); ++k) {
            for (i = 0; i < board.size(); ++i) {
                for (j = 0; j < board[0].size(); ++j)
                    if (backtrack(board, words[k], i, j, 0))
                        break;
                if (j < board[0].size())
                    break;
            }
            if (i < board.size())
                res.emplace_back(words[k]);
        }
        return res;
    }
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k >= word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j]!=word[k])
            return false;
        char temp = board[i][j];
        board[i][j] = 0;
        bool exist = backtrack(board, word, i - 1, j, k + 1) || backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i, j - 1, k + 1) || backtrack(board, word, i, j + 1, k + 1);
        board[i][j] = temp;
        return exist;
    }
};