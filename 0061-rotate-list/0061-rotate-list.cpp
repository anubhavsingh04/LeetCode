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
        int n=0;
        ListNode*curr=head;
        while(curr)
        {
            curr=curr->next;
            n++;
        }
        k=k%n;
        for(int i=0;i<k;i++)
        {
            ListNode* tmp=head,*ptr;
            while(tmp->next->next)
            {
                tmp=tmp->next;
            }
            ptr=tmp->next;
            tmp->next=NULL;
            ptr->next=head;
            head=ptr;
        }
        return head;
    }
};