/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(pRoot);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while (n--) {
                TreeNode* p = q.front();
                q.pop();
                temp.push_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            res.emplace_back(temp);
        }
        return res;
    }
     
};