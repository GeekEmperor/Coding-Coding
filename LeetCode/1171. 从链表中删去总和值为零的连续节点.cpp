class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        unordered_map<int, ListNode*> m;
        int sum = 0;
        for (ListNode* p = &dummy; p; p = p->next) {
            sum += p->val;
            m[sum] = p;
        }
        sum = 0;
        for (ListNode* p = &dummy; p; p = p->next) {
            sum += p->val;
            p->next = m[sum]->next;
        }
        return dummy.next;
    }
};