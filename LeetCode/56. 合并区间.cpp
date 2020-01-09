class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> temp = intervals[0];
        for (int i = 0; i < intervals.size(); ++i) {
            if (temp[1] >= intervals[i][0])
                temp[1] = max(temp[1], intervals[i][1]);
            else {
                res.emplace_back(temp);
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }
        res.emplace_back(temp);
        return res;
    }
};