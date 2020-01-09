class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        string res(max(m, n) + 1, 0);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool carry = 0;
        int i = 0;
        for (; i < min(m, n); ++i) {
            res[i] = a[i] + b[i] + carry - '0';
            if (res[i] >= '2') {
                carry = 1;
                res[i] -= 2;
            }
            else
                carry = 0;
        }
        string c = (m > n) ? a : b;
        for (; i < max(m, n); ++i) {
            res[i] = c[i] + carry;
            if (res[i] >= '2') {
                carry = 1;
                res[i] -= 2;
            }
            else
                carry = 0;
        }
        if (carry)
            res[i++] = '1';
        reverse(res.begin(), res.begin() + i);
        return res;
    }
};