class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* a = &dummy, * b = head, * c = head;
        while (c)
        {
            b = a->next;
            while (c && c->val == b->val)
                c = c->next;
            if (c != b->next)
                a->next = c;
            else
                a = a->next;
        }
        return dummy.next;
    }
};