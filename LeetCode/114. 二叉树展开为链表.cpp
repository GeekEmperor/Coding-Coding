class Solution {
public:
    TreeNode* temp;
    void flatten(TreeNode* root) {
        if (!root)
            return;
        temp = root;
        flatten(root->left);
        temp->right = root->right;
        flatten(root->right);
        if (root->left)
            root->right = root->left;
        root->left = 0;
    }
};