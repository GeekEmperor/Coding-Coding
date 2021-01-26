class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder,int a,int b,int c,int d) {
        if(a > b || c > d)
            return 0;
        int i;
        for(i = a; i <= b; ++i)
            if(inorder[i] == postorder[d])
                break;
        TreeNode* root = new TreeNode(postorder[d]);
        root->left = buildTree(inorder, postorder, a, i - 1, c, c - a + i - 1);
        root->right = buildTree(inorder, postorder, i + 1, b, c - a + i, d - 1);
        return root;
    }
};