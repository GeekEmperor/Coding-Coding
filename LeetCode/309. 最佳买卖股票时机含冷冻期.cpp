class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = INT_MIN, pre = 0, temp, n = prices.size();
        for (int i = 0; i < n; ++i) {
            temp = a;
            a = max(a, b + prices[i]);
            b = max(b, pre - prices[i]);
            pre = temp;
        }
        return a;
    }
};