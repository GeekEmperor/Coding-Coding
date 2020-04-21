class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while (true) {
            for (int j = l; j <= r; ++j)
                v.push_back(matrix[t][j]);
            if (++t > b)
                break;
            for (int i = t; i <= b; ++i)
                v.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int j = r; j >= l; --j)
                v.push_back(matrix[b][j]);
            if (--b < t)
                break;
            for (int i = b; i >= t; --i)
                v.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return v;
    }
};