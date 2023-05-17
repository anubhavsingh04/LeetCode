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
    int pairSum(ListNode* head) {
        int len=0;
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<slow->val<<' '<<endl;
        ListNode*prev=NULL,*curr=slow,*nxt;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode*ptr1=head,*ptr2=prev;
        // cout<<prev->val<<' '<<endl;
        int ans=0;
        while(ptr2)
        {
            ans=max(ans,ptr1->val+ptr2->val);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ans;
    }
};