/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if (m.count(root))
            return m[root];
        int a = root->val;
        if (root->left)
            a += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            a += rob(root->right->left) + rob(root->right->right);
        int b = rob(root->left) + rob(root->right);
        m[root] = max(a,b);
        return max(a, b);
    }
};