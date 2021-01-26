class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1, s;
        while (i < j) {
            s = numbers[i] + numbers[j];
            if (s == target)
                break;
            else if (s < target)
                ++i;
            else
                --j;
        }
        vector<int> res = {i + 1, j + 1};
        return res;
    }
};
