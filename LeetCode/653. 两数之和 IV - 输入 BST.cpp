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
    bool findTarget(TreeNode* root, int k) {
        vector<int> val;
        dfs(root, val);
        int i = 0, j = val.size() - 1, s;
        while (i < j) {
            s = val[i] + val[j];
            if (s == k)
                return true;
            else if (s < k)
                ++i;
            else
                --j;
        }
        return false;
    }
    void dfs(TreeNode* root, vector<int>& val) {
        if (!root)
            return;
        dfs(root->left, val);
        val.emplace_back(root->val);
        dfs(root->right, val);
    }
};