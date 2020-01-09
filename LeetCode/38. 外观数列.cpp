class Solution {
public:
    string countAndSay(int n) {
        string a = "1";
        for (int i = 2; i <= n; ++i) {
            string b;
            a += '0';
            for (int j = 0, k = 0; k < a.size(); ++k) {
                if (a[k] != a[j]) {
                    b += k - j + '0';
                    b += a[j];
                    j = k;
                }
            }
            a = b;
        }
        return a;
    }
};