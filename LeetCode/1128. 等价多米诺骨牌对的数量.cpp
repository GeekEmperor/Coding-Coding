class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> counts(10, vector<int>(10, 0));
        for (int i = 0; i < dominoes.size(); ++i)
        {
            int a = dominoes[i][0], b = dominoes[i][1];
            if (a <= b)
                ++counts[a][b];
            else
                ++counts[b][a];
        }
        int count = 0;
        for (int i = 1; i <= 9; ++i)
            for (int j = i; j <= 9; ++j)
                count += counts[i][j] * (counts[i][j]-1) / 2;
        return count;
    }
};