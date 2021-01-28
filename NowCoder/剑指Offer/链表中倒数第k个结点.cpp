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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p = pListHead, * q = p;
        while (p && k) {
            p = p->next;
            --k;
        }
        if (k)
            return nullptr;
        while (p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};