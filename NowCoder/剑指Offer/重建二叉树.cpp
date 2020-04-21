/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return construct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
    TreeNode* construct(vector<int>& pre, vector<int>& vin, int a, int b, int c, int d) {
        if (a > b)
            return nullptr;
        else if (a == b)
            return new TreeNode(pre[a]);
        int i;
        for (i = c; i <= d; ++i)
            if (vin[i] == pre[a])
                break;
        TreeNode* node = new TreeNode(pre[a]);
        node->left = construct(pre, vin, a + 1, a - c + i, c, i - 1);
        node->right = construct(pre, vin, b - d + i + 1, b, i + 1, d);
        return node;
    }
};