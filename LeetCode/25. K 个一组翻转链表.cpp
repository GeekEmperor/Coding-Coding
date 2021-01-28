/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i;
        ListNode dummy;
        ListNode *once = head, *twice = head, *tail = &dummy, *temp;
        while (true) {
            for (i = 0; once && i < k; ++i)
                once = once->next;
            if (i < k)
                break;
            once = twice;
            for (i = 0; i < k; ++i) {
                temp = twice->next;
                twice->next = tail->next;
                tail->next = twice;
                twice = temp;
            }
            tail = once;
            once = twice;
        }
        tail->next = twice;
        return dummy.next;
    }
};