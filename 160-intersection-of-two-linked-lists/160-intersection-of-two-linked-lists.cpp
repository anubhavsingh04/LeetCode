/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*tmp=headA,*ptr=headB;
        map<ListNode*,int>m;
        while(tmp!=NULL)
        {
            m[tmp]++;
            tmp=tmp->next;
        }
        while(ptr!=NULL)
        {
            if(m[ptr]>0) return ptr;
            ptr=ptr->next;
        }
        return NULL;
    }
};