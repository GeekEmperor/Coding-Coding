class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode Node(0);
        Node.next = l1;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* r = &Node;
        while (p && q)
        {
            if (p->val <= q->val)
            {
                r->next = p;
                r = p;
                p = p->next;
            }
            else
            {
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        while (p)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        while (q)
        {
            r->next = q;
            r = q;
            q = q->next;
        }
        r->next = nullptr;
        return Node.next;
    }
};