class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void backtrack(int n, int k, int i) {
        if (temp.size() == k) {
            res.emplace_back(temp);
            return;
        }
        for (int j = i; j <= n; ++j) {
            temp.push_back(j);
            backtrack(n, k, j + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }
};