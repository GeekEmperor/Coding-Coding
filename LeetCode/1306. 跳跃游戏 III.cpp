class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> v(n, false);
        v[start] = true;
        stack<int> s;
        s.push(start);
        while (!s.empty()) {
            int i = s.top();
            s.pop();
            if (!arr[i])
                return true;
            int j = i + arr[i];
            if (j < n && !v[j]) {
                v[j] = true;
                s.push(j);
            }
            j = i - arr[i];
            if (j >= 0 && !v[j]) {
                v[j] = true;
                s.push(j);
            }
        }
        return false;
    }
};