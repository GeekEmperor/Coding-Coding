class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), res = 0, i = 0;
        if (str[i] == '+' || str[i] == '-')
            ++i;
        else if (!isdigit(str[i]))
            return 0;
        for (; i < n; ++i)
            if (!isdigit(str[i]))
                return 0;
            else
                res = res * 10 + str[i] - '0';
        return str[0] == '-' ? -res : res;
    }
};