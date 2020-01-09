class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = m - 1;
        while (l <= r) {
            int i = (l + r) >> 1;
            if (matrix[i][0] == target)
                return true;
            else if (matrix[i][0] < target)
                l = i + 1;
            else
                r = i - 1;
        }
        if (r < 0)
            return false;
        int i = r;
        l = 0, r = n - 1;
        while (l <= r) {
            int j = (l + r) >> 1;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                l = j + 1;
            else
                r = j - 1;
        }
        return false;
    }
};