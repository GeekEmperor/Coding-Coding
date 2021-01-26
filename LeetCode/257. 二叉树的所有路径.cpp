class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector<string> res;
        dfs(res, "", root);
        return res;
    }
    void dfs(vector<string>& res, string path, TreeNode* root) {
        if (!root->left && !root->right) {
            path += to_string(root->val);
            res.emplace_back(path);
            return;
        }
        path += to_string(root->val);
        path += "->";
        if (root->left)
            dfs(res, path, root->left);
        if (root->right)
            dfs(res, path, root->right);
    }
};