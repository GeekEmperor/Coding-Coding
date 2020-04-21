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
    vector<vector<int>> res;
    vector<int> temp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        dfs(root, expectNumber);
        return res;
    }
    void dfs(TreeNode* root, int expectNumber) {
        if (!root)
            return;
        expectNumber -= root->val;
        temp.push_back(root->val);
        if (!expectNumber && !root->left && !root->right)
            res.emplace_back(temp);
        dfs(root->left, expectNumber);
        dfs(root->right, expectNumber);
        temp.pop_back();
    }
};