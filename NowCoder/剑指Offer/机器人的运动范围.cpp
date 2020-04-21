class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> matrix(rows, vector<bool>(cols, false));
        return movingCount(matrix, threshold, rows, cols, 0, 0);
    }
     
    int movingCount(vector<vector<bool>>& matrix, int threshold, int rows, int cols, int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] || sum(i, j) > threshold)
            return 0;
        matrix[i][j] = true;
        return 1 + movingCount(matrix, threshold, rows, cols, i, j - 1)
            + movingCount(matrix, threshold, rows, cols, i, j + 1)
            + movingCount(matrix, threshold, rows, cols, i + 1, j)
            + movingCount(matrix, threshold, rows, cols, i - 1, j);
    }
     
    int sum(int a, int b)
    {
        int c = 0;
        while (a)
        {
            c += a % 10;
            a /= 10;
        }
        while (b)
        {
            c += b % 10;
            b /= 10;
        }
        return c;
    }
};