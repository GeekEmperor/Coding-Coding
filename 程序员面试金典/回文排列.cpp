class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count[128] = {};
        for (char c : s)
            ++count[c];
        bool flag = s.size() & 1;
        for (int v : count)
            if (v & 1) {
                if (!flag)
                    return false;
                else
                    flag = false;
            }
        return true;
    }
};