class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (hasPath(matrix, rows, cols, i, j, str))
                    return true;
        return false;
    }
     
    bool hasPath(char* matrix, int rows, int cols, int i, int j, char* str)
    {
        if (!*str)
            return true;
        if (i < 0 || j < 0 || i >= rows || j >= cols || matrix[i * cols + j] != *str)
            return false;
        char temp = matrix[i * cols + j];
        matrix[i * cols + j] = '\0';
        bool flag =  (hasPath(matrix, rows, cols, i + 1, j, str + 1))
            || (hasPath(matrix, rows, cols, i - 1, j, str + 1))
            || (hasPath(matrix, rows, cols, i, j + 1, str + 1))
            || (hasPath(matrix, rows, cols, i, j - 1, str + 1));
        matrix[i * cols + j] = temp;
        return flag;
    }
};