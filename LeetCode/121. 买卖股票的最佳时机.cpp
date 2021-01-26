class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), p = INT_MAX, res = 0;
        for (int i = 0; i < n; ++i) {
            if (prices[i] < p)
                p = prices[i];
            else
                res = max(res, prices[i] - p);
        }
        return res;
    }
};