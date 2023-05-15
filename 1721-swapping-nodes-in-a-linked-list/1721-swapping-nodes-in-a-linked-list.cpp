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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode*curr=head,*curr2=head;
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        for(int i=0;i<k-1;i++)
        {
            curr2=curr2->next;
        }
        // cout<<curr2->val<<endl;
        curr=head;
        // cout<<len<<endl;
        for(int i=0;i<len-k;i++)
        {
            curr=curr->next;
        }
        // cout<<curr->val<<endl;
        swap(curr->val,curr2->val);
        return head;
    }
};