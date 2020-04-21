class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int i = 0, j = 0, n = str.size();
        for (; j < n; ++j)
            if (str[j] == ' ') {
                reverse(str.begin() + i, str.begin() + j);
                i = j + 1;
            }
        reverse(str.begin() + i, str.begin() + j);
        return str;
    }
};