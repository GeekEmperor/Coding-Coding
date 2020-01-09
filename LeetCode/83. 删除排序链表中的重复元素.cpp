class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* p = head, * q = head;
        while (q) {
            if (q->val != p->val) {
                p->next = q;
                p = q;
            }
            q = q->next;
        }
        p->next = nullptr;
        return head;
    }
};