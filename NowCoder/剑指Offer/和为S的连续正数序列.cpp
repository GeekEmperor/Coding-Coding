class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        for (int i = (sum + 1) >> 1; i >= 2; --i) {
            int average = sum / i;
            if (i & 1) {
                if ((average * i == sum) && (average - (i >> 1) > 0)) {
                    vector<int> temp;
                    for (int j = average - (i >> 1); j <= average + (i >> 1); ++j)
                        temp.push_back(j);
                    res.emplace_back(temp);
                }
            }
            else {
                if (((2 * average + 1) * (i >> 1) == sum) && (average - (i >> 1) + 1 > 0)) {
                    vector<int> temp;
                    for (int j = average - (i >> 1) + 1; j <= average + (i >> 1); ++j)
                        temp.push_back(j);
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }
};