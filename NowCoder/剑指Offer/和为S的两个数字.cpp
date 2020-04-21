class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i = 0, j = array.size() - 1;
        while (i < j) {
            int k = array[i] + array[j];
            if (k == sum)
                return {array[i], array[j]};
            else if (k > sum)
                --j;
            else
                ++i;
        }
        return {};
    }
};