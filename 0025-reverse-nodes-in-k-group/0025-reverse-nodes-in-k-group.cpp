/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head,*nxt=NULL,*prev=NULL;
        int len=0;
        ListNode*tmp=head;
        for(int i=0;i<k;i++)
        {
            if(!tmp) return head;
            else tmp=tmp->next;
        }
        while(curr!=NULL && len<k)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            len++;
        }
        head->next=reverseKGroup(tmp,k);
        return prev;
    }
};