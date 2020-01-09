class Solution {
public:
    vector<vector<vector<TreeNode*>>> m;
    vector<TreeNode*> generateTrees(int n) {
        if (n) {
            m.resize(n);
            for (int i = 0; i < n; ++i)
                m[i].resize(n);
            return generate(1, n);
        }
        else
            return {};
    }
    vector<TreeNode*> generate(int s, int e) {
        if (s > e)
            return { nullptr };
        if (!m[s - 1][e - 1].empty())
            return m[s - 1][e - 1];
        vector<TreeNode*> c;
        for (int i = s; i <= e; ++i) {
            vector<TreeNode*> a(generate(s, i - 1));
            vector<TreeNode*> b(generate(i + 1, e));
            for (int j = 0; j < a.size(); ++j)
                for (int k = 0; k < b.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = a[j];
                    root->right = b[k];
                    c.emplace_back(root);
                }
        }
        m[s - 1][e - 1] = c;
        return c;
    }
};