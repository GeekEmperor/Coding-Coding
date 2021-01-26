class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return 0;
        Node *p = root, *q = 0, *r = 0;
        root->next = 0;
        while(p) {
            q = p;
            while(q) {
                r = q->next;
                while(r) {
                    if(r->left) {
                        r = r->left;
                        break;
                    }
                    if(r->right) {
                        r = r->right;
                        break;
                    }
                    r = r->next;
                }
                if(q->right) q->right->next = r; 
                if(q->left) q->left->next = q->right ? q->right : r;
                q = q->next;
            }
            while(p) {
                if(p->left) {
                    p = p->left;
                    break;
                }
                if(p->right) {
                    p = p->right;
                    break;
                }
                p = p->next;
            }
        }
        return root;
    }
};