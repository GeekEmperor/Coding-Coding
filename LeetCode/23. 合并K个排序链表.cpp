struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                pq.push(lists[i]);
        ListNode dummy(0);
        ListNode* p = &dummy, * q;
        while (!pq.empty()) {
            q = pq.top();
            pq.pop();
            p->next = q;
            p = q;
            if (q->next)
                pq.push(q->next);
        }
        return dummy.next;
    }
};