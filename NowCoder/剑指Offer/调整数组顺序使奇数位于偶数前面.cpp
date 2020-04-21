class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i = 0, j = 0, n = array.size();
        vector<int> temp(array);
        for (int k = 0; k < n; ++k)
            if (array[k] & 1)
                ++j;
        for (int k = 0; k < n; ++k)
            if (temp[k] & 1)
                array[i++] = temp[k];
            else
                array[j++] = temp[k];
    }
};