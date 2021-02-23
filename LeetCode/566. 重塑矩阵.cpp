class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m*n != r*c)
            return nums;
        vector<vector<int>> matrix(r, vector<int>(c));
        int a = 0, b = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                matrix[a][b] = nums[i][j];
                if (++b == c) {
                    ++a;
                    b = 0;
                }
            }
        return matrix;
    }
};