class Solution {
public:
    int Fibonacci(int n) {
        int a = 1, b = 0, c = 1;
        for (int i = 0; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};