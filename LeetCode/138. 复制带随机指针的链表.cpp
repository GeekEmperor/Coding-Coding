class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return 0;
        Node *p = head, *q, *r;
        while(p) {
            r = new Node(p->val, p->next, 0);
            q = p->next;
            p->next = r;
            p = q;
        }
        p = head;
        while(p) {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head, r = head->next;
        while(p->next) {
            q = p->next;
            p->next = q->next;
            p = q;
        }
        return r;
    }
};