class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = INT_MIN, c = 0, d = INT_MIN, n = prices.size();
        for (int i = 0; i < n; ++i) {
            c = max(c, d + prices[i]);
            d = max(d, a - prices[i]);
            a = max(a, b + prices[i]);
            b = max(b, - prices[i]);
        }
        return c;
    }
};