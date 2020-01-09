class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size();
        stack<int> st;
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == '(')
                st.push(j);
            else if (st.empty())
                i = j + 1;
            else {
                st.pop();
                res = st.empty() ? max(res, j - i + 1) : max(res, j - st.top());
            }
        }
        return res;
    }
};