class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root)
            return;
        sum -= root->val;
        temp.emplace_back(root->val);
        if (!root->left && !root->right) {
            if (!sum)
                res.emplace_back(temp);
            temp.pop_back();
            return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        temp.pop_back();
    }
};