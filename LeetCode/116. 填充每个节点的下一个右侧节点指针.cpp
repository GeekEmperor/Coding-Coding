class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return 0;
        Node *start = root, *cur = 0;
        root->next = 0;
        while (start->left) {
            cur = start;
            while (cur) {
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : 0;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};