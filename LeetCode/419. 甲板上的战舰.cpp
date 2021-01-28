class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return 0;
        int m = board.size(), n = board[0].size(), count = 0;
        for (int i = 0; i < m; ++i) {
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.')
                    flag = true;
                else if (flag)
                    ++count, flag = false;
            }
        }
        for (int j = 0; j < n; ++j) {
            bool flag = true;
            for (int i = 0; i < m; ++i) {
                if (board[i][j] == '.')
                    flag = true;
                else if (flag)
                    ++count, flag = false;
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'X')
                    --count;
        return count;
    }
};