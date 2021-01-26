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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return {};
        int n;
        double s;
        TreeNode* p;
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while (!q.empty()) {
            s = 0;
            n = q.size();
            for (int i = 0; i < n; ++i) {
                p = q.front();
                q.pop();
                s += p->val;
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            res.emplace_back(s / n);
        }
        return res;
    }
};