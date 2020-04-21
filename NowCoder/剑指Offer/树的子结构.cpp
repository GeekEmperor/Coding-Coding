/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;
        queue<TreeNode*> q;
        q.push(pRoot1);
        while (!q.empty()) {
            TreeNode* t = q.front();
            if (t->val == pRoot2->val && dfs(t, pRoot2))
                return true;
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return false;
    }
    bool dfs(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2)
            return true;
        if (!pRoot1 || pRoot1->val != pRoot2->val)
            return false;
        return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
    }
};