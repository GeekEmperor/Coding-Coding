class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy, * q = head;
        while (n--)
            q = q->next;
        while (q) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
        return dummy.next;
    }
};