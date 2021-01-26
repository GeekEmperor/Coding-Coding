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
    string smallestFromLeaf(TreeNode* root) {
        if (!root)
            return "";
        return dfs(root, "");
    }
    string dfs(TreeNode* root, string s) {
        s += 'a' + root->val;
        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            return s;
        }
        string left, right;
        if (root->left)
            left = dfs(root->left, s);
        if (root->right)
            right = dfs(root->right, s);
        if (root->left && root->right)
            return left < right ? left : right;
        else if (root->left)
            return left;
        else
            return right;
    }
};