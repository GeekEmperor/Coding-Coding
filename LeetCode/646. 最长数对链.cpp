class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){return a[1] < b[1];});
        int end = INT_MIN, count = 0, n = pairs.size();
        for (int i = 0; i < n; ++i)
            if (pairs[i][0] > end) {
                ++count;
                end = pairs[i][1];
            }
        return count;
    }
};
