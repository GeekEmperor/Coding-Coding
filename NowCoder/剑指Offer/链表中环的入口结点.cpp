/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* fast = pHead, *slow = pHead;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = pHead;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};