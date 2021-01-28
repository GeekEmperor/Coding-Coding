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
private:
    vector<TreeNode*> temp{nullptr};
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        inorder(pRootOfTree);
        int n = temp.size();
        temp.push_back(nullptr);
        for (int i = 1; i < n; ++i) {
            temp[i]->left = temp[i - 1];
            temp[i]->right = temp[i + 1];
        }
        return temp[1];
    }
    void inorder(TreeNode* pRoot)
    {
        if (!pRoot)
            return;
        inorder(pRoot->left);
        temp.push_back(pRoot);
        inorder(pRoot->right);
    }
};