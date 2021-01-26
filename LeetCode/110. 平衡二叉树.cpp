class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return -1 != dfs(root);
    }
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int left = dfs(root->left);
        if (left == -1)
            return -1;
        int right = dfs(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};