class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy, * q, * r;
        for (int i = 0; i < m - 1; ++i)
            p = p->next;
        q = p->next;
        for (int i = m; i < n; ++i)
        {
            r = q->next;
            q->next = r->next;
            r->next = p->next;
            p->next = r;
        }
        return dummy.next;
    }
};