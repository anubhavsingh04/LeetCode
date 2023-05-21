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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        int len=0;
        ListNode*tmp=head,*prev;
        while(tmp)
        {
            prev=tmp;
            tmp=tmp->next;
            len++;
        }
        
        k=k%len;
        prev->next=head;
        k=len-k;
        tmp=head;
        for(int i=0;i<k-1;i++)
        {
            tmp=tmp->next;
        }
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
};