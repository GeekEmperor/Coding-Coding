class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        int min = INT_MAX, max = INT_MIN;
        int count[14] = { 0 };
        for (int i = 0; i < numbers.size(); ++i) {
            if (++count[numbers[i]] >= 2 && numbers[i])
                return false;
            if (numbers[i] && min > numbers[i])
                min = numbers[i];
            if (numbers[i] && max < numbers[i])
                max = numbers[i];
        }
        for (int i = min; i <= max; ++i) {
            if (!count[i] && --count[0] < 0)
                return false;
        }
        return ((min - 1) + (13 - max) >= count[0]) && (max - min + 1 + count[0] >= 5);
    }
};