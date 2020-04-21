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
    bool isSymmetrical(TreeNode* pRoot)
    {
        return pRoot ? isSymmetrical(pRoot->left, pRoot->right) : true;
    }
    bool isSymmetrical(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
            return true;
        if (!left || !right || left->val != right->val)
            return false;
        return isSymmetrical(left->left, right->right) && isSymmetrical(left->right, right->left);
    }
};