class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int area = 0, n = heights.size(), i = 0, j = 0;
        stack<int> s;
        while (i < n) {
            if (s.empty() || heights[s.top()] < heights[i])
                s.push(i++);
            else {
                j = s.top();
                s.pop();
                area = max(area, heights[j] * (s.empty() ? i : (i - s.top() - 1)));
            }
        }
        return area;
    }
};