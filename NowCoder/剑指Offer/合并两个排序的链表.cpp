/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        ListNode* q = (pHead1 ? pHead1 : pHead2);
        while (q) {
            p->next = q;
            q = q->next;
            p = p->next;
        }
        return dummy.next;
    }
};