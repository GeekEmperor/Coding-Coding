class Solution {
public:
    double Power(double base, int exponent) {
        if (!exponent)
            return 1;
        else if (exponent > 0) {
            double temp = Power(base, exponent >> 1);
            if (exponent & 1)
                return temp * temp * base;
            else
                return temp * temp;
        }
        else
            return 1 / Power(base, -exponent);
    }
};