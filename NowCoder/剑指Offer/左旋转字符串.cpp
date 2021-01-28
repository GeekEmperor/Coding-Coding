class Solution {
public:
    string LeftRotateString(string str, int k) {
        if (str.empty())
            return "";
        k %= str.size();
        return str.substr(k) + str.substr(0, k);
    }
};