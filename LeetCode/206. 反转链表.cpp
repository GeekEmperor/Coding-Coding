class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = 0, *q = head, *r;
        while(q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};