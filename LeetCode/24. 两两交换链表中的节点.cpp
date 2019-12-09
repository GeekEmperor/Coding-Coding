class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode x(0);
        x.next = head;
        ListNode* left = &x;
        ListNode* mid = head;
        if (head->next == 0)
            return head;
        ListNode* right = head->next;
        while (mid != 0 && mid->next != 0) {
            mid->next = right->next;
            right->next = mid;
            left->next = right;
            left = mid;
            mid = left->next;
            if (mid != 0)
                right = mid->next;
        }
        return x.next;
    }
};