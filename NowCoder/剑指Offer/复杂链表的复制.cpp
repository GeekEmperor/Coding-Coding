/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return nullptr;
        RandomListNode* p = pHead, * q = nullptr, * r;
        while (p)
        {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = pHead;
        while (p)
        {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = pHead;
        r = pHead->next;
        while (p->next)
        {
            q = p->next;
            p->next = q->next;
            p = q;
        }
        return r;
    }
};