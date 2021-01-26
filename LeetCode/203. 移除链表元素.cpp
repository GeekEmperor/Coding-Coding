class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *q = head;
        while (q) {
            if (q->val == val)
                p->next = q->next;
            else
                p = q;
            q = q->next;
        }
        return dummy.next;
    }
};