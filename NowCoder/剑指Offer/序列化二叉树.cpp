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
    void preorder(TreeNode* root, string& s) {
        if (!root) {
            s += "#!";
            return;
        }
        s += to_string(root->val);
        s += '!';
        preorder(root->left, s);
        preorder(root->right, s);
    }
public:
    char* Serialize(TreeNode *root) {
        string s;
        preorder(root, s);
        char* res = new char[s.size() + 1];
        strcpy(res, s.c_str());
        return res;
    }
     
    TreeNode* Deserialize(char *&str) {
        if (!*str)
            return nullptr;
        if (*str == '#') {
            ++str;
            ++str;
            return nullptr;
        };
        TreeNode* node = new TreeNode(atoi(str));
        while (*str != '!')
            ++str;
        ++str;
        node->left = Deserialize(str);
        node->right = Deserialize(str);
        return node;
    }
};