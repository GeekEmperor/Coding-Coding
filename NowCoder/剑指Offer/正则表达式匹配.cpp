class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (!*pattern)
            return !*str;
        bool flag = (*str == *pattern) || (*str && *pattern == '.');
        if (*(pattern + 1) == '*')
            if (flag)
                return match(str + 1, pattern) || match(str, pattern + 2);
            else
                return match(str, pattern + 2);
        if (flag)
            return match(str + 1, pattern + 1);
        return false;
    }
};