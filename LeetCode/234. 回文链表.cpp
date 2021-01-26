class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* p = head;
        while (p) {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while (p && p->val == s.top()) {
            s.pop();
            p = p->next;
        }
        return !p;
    }
};