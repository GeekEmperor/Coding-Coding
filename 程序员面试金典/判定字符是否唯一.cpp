class Solution {
public:
    bool isUnique(string astr) {
        bool exist[128] = {};
        for (char c : astr) {
            if (exist[c])
                return false;
            exist[c] = true;
        }
        return true;
    }
};