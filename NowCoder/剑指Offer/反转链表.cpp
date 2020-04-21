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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p = nullptr, * q = pHead, * r = q->next;
        while (q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};