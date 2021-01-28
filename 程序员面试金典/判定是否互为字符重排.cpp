class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int count1[128] = {};
        for (char c : s1)
            ++count1[c];
        int count2[128] = {};
        for (char c : s2)
            ++count2[c];
        for (int i = 0; i < 128; ++i)
            if (count1[i] != count2[i])
                return false;
        return true;
    }
};