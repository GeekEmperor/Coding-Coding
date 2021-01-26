class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    int dfs(TreeNode* root, int& k) {
        if (!root)
            return -1;
        int a = dfs(root->left, k);
        if (a >= 0)
            return a;
        if (--k == 0)
            return root->val;
        int b = dfs(root->right, k);
        if (b >= 0)
            return b;
        return -1;
    }
};