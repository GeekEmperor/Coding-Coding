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
private:
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (!pRoot)
            return nullptr;
        TreeNode* left = KthNode(pRoot->left, k);
        if (left)
            return left;
        if (++count == k)
            return pRoot;
        TreeNode* right = KthNode(pRoot->right, k);
        if (right)
            return right;
        return nullptr;
    }
};
