class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n = str.length(), res = INT_MAX;
        vector<int> index(128, INT_MIN);
        for (int i = 0; i < n; ++i)
            if (index[str[i]] == INT_MIN)
                index[str[i]] = i;
            else
                index[str[i]] = INT_MAX;
        for (int i = 0; i < 128; ++i)
            if (index[i] != INT_MIN && index[i] < res)
                res = index[i];
        return res == INT_MAX ? -1 : res;
    }
};