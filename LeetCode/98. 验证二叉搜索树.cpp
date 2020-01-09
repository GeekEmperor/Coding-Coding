class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long left, long right) {
        if (!root)
            return true;
        if (root->val <= left || root->val >= right)
            return false;
        return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
    }
};