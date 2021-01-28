class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res = INT_MIN, sum = 0, n = array.size();
        for (int i = 0; i < n; ++i) {
            sum += array[i];
            if (sum > res)
                res = sum;
            else if (sum < 0)
                sum = 0;
        }
        return res;
    }
};