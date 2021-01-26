/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "n,";
        string str = to_string(root->val) + ',';
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data = "") {
        static int i = 0;
        static string str;
        if (!data.empty()) {
            str = data;
            i = 0;
        }
        int j = str.find(',', i);
        string temp = str.substr(i, j - i);
        i = j + 1;
        if (temp == "n")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(temp));
        node->left = deserialize();
        node->right = deserialize();
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));