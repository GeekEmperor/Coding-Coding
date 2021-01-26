class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *right = sortList(slow->next);
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode dummy(0);
        ListNode *p = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        return dummy.next;
    }
};
