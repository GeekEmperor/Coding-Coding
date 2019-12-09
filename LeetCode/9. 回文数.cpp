class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return 0;
        int y = x, z = 0;
        while (y != 0)
        {
            z *= 10;
            z += y % 10;
            y /= 10;
        }
        return z == x;
    }
};