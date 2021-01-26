class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        int n;
        TreeNode* p;
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty()) {
            n = q.size();
            vector<int> temp;
            while (n--) {
                p = q.front();
                q.pop();
                temp.emplace_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            res.emplace_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};