class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode* p = head, * q = head;
        int n = 1;
        while (p->next)
        {
            p = p->next;
            ++n;
        }
        p->next = head;
        k %= n;
        for (int i = 0; i < n - k - 1; ++i)
            q = q->next;
        p = q->next;
        q->next = 0;
        return p;
    }
};