class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = INT_MIN, n = prices.size(), t;
        for (int i = 0; i < n; ++i) {
            t = a;
            a = max(t, b + prices[i]);
            b = max(b, t - prices[i]);
        }
        return a;
    }
};