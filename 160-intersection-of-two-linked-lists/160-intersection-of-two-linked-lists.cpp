/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Map soln --> Put in map and check for same node is there or not TC: O(m+n) ,SC: O(m)

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode*p=headA,*q=headB;
//         map<ListNode*,int>m;
//         while(p!=NULL)
//         {
//             m[p]++;
//             p=p->next;
//         }
//         while(q!=NULL)
//         {
//             if(m[q]>0) return q;
//             q=q->next;
//         }
//         return NULL;
//     }
// };

// len diffrence soln --> make the length of both ll same and iterate until get same node 
// TC: O(m+n), SC: O(1)

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int a=0,b=0;
//         ListNode*p=headA,*q=headB;
//         while(p!=NULL)
//         {
//             a++;
//             p=p->next;
//         }
//         while(q!=NULL)
//         {
//             b++;
//             q=q->next;
//         }
//         p=headA;
//         q=headB;
//         int diff=abs(a-b);
//         if(a>b)
//         {
//             while(diff--)
//                 p=p->next;
//         }
//         else 
//         {
//             while(diff--)
//                 q=q->next;
//         }
//         while(p!=NULL&&q!=NULL)
//         {
//             if(p==q)
//                 return p;
//             else
//             {
//                 p=p->next;
//                 q=q->next;
//             }
//         }
//         return NULL;
//     }
// };

// Two Pointer Soln

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*p=headA,*q=headB;
        while(p!=q)
        {
            if(p==NULL) p=headB;
            else  p=p->next;
            
            if(q==NULL) q=headA;
            else q=q->next;
        }
        return p;
    }
};