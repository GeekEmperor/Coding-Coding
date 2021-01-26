class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& a, auto& b){return a[0] - a[1] < b[0] - b[1];});
        int n = costs.size(), m = n / 2, res = 0;
        for (int i = 0; i < m; ++i)
            res += costs[i][0];
        for (int i = m; i < n; ++i)
            res += costs[i][1];
        return res;
    }
};