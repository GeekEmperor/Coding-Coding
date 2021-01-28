class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return IsBalanced(pRoot) != -1;
    }
    int IsBalanced(TreeNode* pRoot) {
        if (!pRoot)
            return 0;
        int left = IsBalanced(pRoot->left);
        if (left == -1)
            return -1;
        int right = IsBalanced(pRoot->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};