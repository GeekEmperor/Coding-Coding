class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int i = 0, j = 0, n = pushV.size();
        while (j < n) {
            if (!s.empty() && s.top() == popV[j]) {
                s.pop();
                ++j;
            }
            else if (i < n) {
                s.push(pushV[i]);
                ++i;
            }
            else
                return false;
        }
        return true;
    }
};