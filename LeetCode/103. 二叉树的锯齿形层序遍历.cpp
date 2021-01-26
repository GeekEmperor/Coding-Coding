class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        bool dir = 0;
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
            if (dir)
                reverse(temp.begin(), temp.end());
            dir ^= 1;
            res.emplace_back(temp);
        }
        return res;
    }
};