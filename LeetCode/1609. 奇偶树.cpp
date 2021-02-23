class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int flag = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            flag = !flag;
            int size = q.size(), last = flag ? INT_MIN : INT_MAX;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                int cur = node->val;
                if ((cur & 1) != flag)
                    return false;
                if (flag && cur <= last)
                    return false;
                if (!flag && cur >= last)
                    return false;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                last = cur;
            }
        }
        return true;
    }
};
