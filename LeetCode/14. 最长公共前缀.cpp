class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)
            return "";
        if (n == 1)
            return strs[0];
        int i, j = 0;
        string s = "";
        while (true)
        {
            i = 1;
            while (i < n && strs[i][j] == strs[0][j])
                i++;
            if (i < n)
                break;
            s += strs[0][j];
            j++;
        }
        return s;
    }
};