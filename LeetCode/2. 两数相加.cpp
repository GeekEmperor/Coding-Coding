class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        int carry = 0, val;
        while (l1 && l2) {
            val = l1->val + l2->val + carry;
            if (val >= 10) {
                p->next = new ListNode(val - 10);
                carry = 1;
            }
            else {
                p->next = new ListNode(val);
                carry = 0;
            }
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l = l1 ? l1 : l2;
        while (l) {
            val = l->val + carry;
            if (val >= 10) {
                p->next = new ListNode(val - 10);
                carry = 1;
            }
            else {
                p->next = new ListNode(val);
                carry = 0;
            }
            p = p->next;
            l = l->next;
        }
        if (carry)
            p->next = new ListNode(1);
        return dummy.next;
    }
};