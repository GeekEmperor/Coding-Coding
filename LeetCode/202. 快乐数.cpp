class Solution {
public:
    bool isHappy(int n) {
        int temp;
        while (n != 1 && n != 4) {
            temp = 0;
            while (n) {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        }
        return n == 1;
    }
};
