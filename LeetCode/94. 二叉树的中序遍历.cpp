class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }
    void inorder(vector<int>& res, TreeNode* root) {
        if (!root)
            return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
};