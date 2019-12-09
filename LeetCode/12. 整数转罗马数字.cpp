class Solution {
public:
    string intToRoman(int num) {
        char ch[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        int val[7] = { 1, 5, 10, 50, 100, 500, 1000 };
        string res;
        for (int i = 6; i >= 0; i -= 2) {
            int x = num / val[i], y = 0;
            if (x == 9) {
                res += ch[i];
                res += ch[i + 2];
            }
            else if (x >= 5) {
                res += ch[i + 1];
                y = x - 5;
            }
            else if (x == 4) {
                res += ch[i];
                res += ch[i + 1];
            }
            else
                y = x;
            while (y--)
                res += ch[i];
            num %= val[i];
        }
        return res;
    }
};