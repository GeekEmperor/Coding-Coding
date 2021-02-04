class Solution {
public:
    vector<bool> nodes;
    vector<TreeNode*> ans;
    void traverse(TreeNode* node, TreeNode* father, int flag) {
        if (!node)
            return;
        if (nodes[node->val-1]) {
            if (flag == -1)
                father->left = nullptr;
            else if (flag == 1)
                father->right = nullptr;
            traverse(node->left, node, 0);
            traverse(node->right, node, 0);
        }
        else {
            if (!flag)
                ans.emplace_back(node);
            traverse(node->left, node, -1);
            traverse(node->right, node, 1);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        nodes.resize(1000, false);
        ans.clear();
        for (int n : to_delete)
            nodes[n-1] = true;
        traverse(root, nullptr, 0);
        return ans;
    }
};