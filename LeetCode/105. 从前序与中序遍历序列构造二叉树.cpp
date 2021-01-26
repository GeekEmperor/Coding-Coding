class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int a,int b,int c,int d) {
        if(a > b || c > d)
            return 0;
        int i;
        for(i = c; i <= d; ++i)
            if(inorder[i] == preorder[a])
                break;
        TreeNode* root = new TreeNode(preorder[a]);
        root->left = buildTree(preorder, inorder, a + 1, a + i - c, c, i - 1);
        root->right = buildTree(preorder, inorder, a + i - c + 1, b, i + 1, d);
        return root;
    }
};