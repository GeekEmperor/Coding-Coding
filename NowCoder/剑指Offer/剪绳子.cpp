class Solution {
public:
    int cutRope(int number) {
        if (number <= 3)
            return number - 1;
        else if (number % 3 == 2)
            return pow(3, number / 3) * 2;
        else if (number % 3 == 1)
            return pow(3, number / 3 - 1) * 4;
        else
            return pow(3, number / 3);
    }
};