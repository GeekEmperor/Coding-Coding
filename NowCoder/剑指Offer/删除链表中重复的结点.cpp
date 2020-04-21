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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode dummy(0);
        dummy.next = pHead;
        ListNode* p = &dummy, *q = pHead;
        while (q) {
            if (!q->next || p->next->val != q->next->val) {
                p = q;
                q = q->next;
            }
            else {
                while (q && q->val == p->next->val)
                    q = q->next;
                p->next = q;
            }
        }
        return dummy.next;
    }
};