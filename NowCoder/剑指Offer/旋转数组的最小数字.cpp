class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        int l = 1, r = rotateArray.size() - 1, m, pivot = rotateArray[0];
        while (l <= r) {
            m = (l + r) >> 1;
            if (rotateArray[m] < pivot)
                r = m - 1;
            else
                l = m + 1;
        }
        return rotateArray[l];
    }
};