class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int n = intervals.size(), left = 0, right = n - 1, mid, i, j;
        while (left <= right) {
            mid = (left + right) / 2;
            if (intervals[mid][1] >= newInterval[0])
                right = mid - 1;
            else
                left = mid + 1;
        }
        i = left;
        right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (intervals[mid][0] > newInterval[1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        j = right;
        if (i < n)
            newInterval[0] = min(intervals[i][0], newInterval[0]);
        if (j >= 0)
            newInterval[1] = max(intervals[j][1], newInterval[1]);
        if (i <= j)
            intervals.erase(intervals.begin() + i, intervals.begin() + j + 1);
        intervals.insert(intervals.begin() + i, newInterval);
        return intervals;
    }
};