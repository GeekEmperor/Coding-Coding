class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int a = 1, b = (s[0] != '0'), c;
        for (int i = 1; i < n; ++i) {
            c = (s[i] == '0') ? 0 : b;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                c += a;
            a = b;
            b = c;
        }
        return b;
    }
};