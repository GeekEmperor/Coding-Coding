class Solution {
public:
    int rectCover(int number) {
        if (!number)
            return 0;
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < number; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};