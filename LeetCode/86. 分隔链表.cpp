class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==0||head->next==0)
            return head;
        else
        {
        ListNode *s=0,*b=0,*p=head,*q,*r;
        while(p!=0)
        {
            if(p->val<x)
            {
                if(s==0)
                {
                    s=p;
                    r=s;
                }
                else
                {
                    s->next=p;
                    s=p;
                }
            }
            else
            {
                if(b==0)
                {
                    b=p;
                    q=b;
                }
                else
                {
                    b->next=p;
                    b=p;
                }
            }
            p=p->next;
        }
        if(s==0)
        {
            r=q;
            b->next=0;
        }
        else if(b==0)
        {
            s->next=0;
        }
        else
        {
            s->next=q;
            b->next=0;
        }
        return r;
        }
    }
};