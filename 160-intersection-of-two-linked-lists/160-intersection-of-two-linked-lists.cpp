/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode*tmp=headA,*ptr=headB;
//         map<ListNode*,int>m;
//         while(tmp!=NULL)
//         {
//             m[tmp]++;
//             tmp=tmp->next;
//         }
//         while(ptr!=NULL)
//         {
//             if(m[ptr]>0) return ptr;
//             ptr=ptr->next;
//         }
//         return NULL;
//     }
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0,b=0;
        ListNode*p=headA,*q=headB;
        while(p!=NULL)
        {
            a++;
            p=p->next;
        }
        while(q!=NULL)
        {
            b++;
            q=q->next;
        }
        p=headA;
        q=headB;
        int diff=abs(a-b);
        if(a>b)
        {
            while(diff--)
                p=p->next;
        }
        else 
        {
            while(diff--)
                q=q->next;
        }
        while(p!=NULL&&q!=NULL)
        {
            if(p==q)
                return p;
            else
            {
                p=p->next;
                q=q->next;
            }
        }
        return NULL;
    }
};