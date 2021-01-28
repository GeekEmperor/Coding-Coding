class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size(), live = 0, res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (numbers[i] == res)
                ++live;
            else if (--live < 0) {
                res = numbers[i];
                live = 1;
            }
        }
        live = 0;
        for (int i = 0; i < n; ++i)
            if (numbers[i] == res)
                ++live;
        return (live << 1) > n ? res : 0;
    }
};