class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(res, root);
        return res;
    }
    void dfs(vector<int>& res, TreeNode* root) {
        if (!root)
            return;
        dfs(res, root->left);
        dfs(res, root->right);
        res.emplace_back(root->val);
    }
};
