class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size(), ans = 0;
        int i = 0, j = 0, k = 0;
        for (; i < n; ++i) {
            if (tree[i] != tree[k]) {
                if (k && tree[i] != tree[k-1]) {
                    ans = max(ans, i - j);
                    j = k;
                }
                k = i;
            }
        }
        ans = max(ans, i - j);
        return ans;
    }
};