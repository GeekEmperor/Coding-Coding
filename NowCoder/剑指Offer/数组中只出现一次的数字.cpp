class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int n = data.size(), res = 0, index = 0;
        for (int i = 0; i < n; ++i)
            res ^= data[i];
        while (!(res & 1)) {
            res >>= 1;
            ++index;
        }
        *num1 = *num2 = 0;
        for (int i = 0; i < n; ++i)
            if ((data[i] >> index) & 1)
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
    }
};