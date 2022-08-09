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

// reversal logic is nxt=curr->next; curr->next=prev; prev=curr; curr =nxt;
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//        ListNode*dummy=new ListNode(-1);
//         dummy->next=head;
//         ListNode*prev=NULL;
//         ListNode*curr=dummy;
        
//         for(int i=0;i<left;i++)
//         {
//             prev=curr;
//             curr=curr->next;
//         }
//         ListNode*curr1=curr,*prev1=prev,*nxt; 
        
//         // reversing 
//         for(int i=left;i<=right;i++)
//         {
//             nxt=curr1->next;
//             curr1->next=prev1;
//             prev1=curr1;
//             curr1=nxt;
//         }
//         // connecting 
//         curr->next=curr1;
//         prev->next=prev1;
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode*curr=head;
        for(int i=0;i<left-1;i++)
        {
            curr=curr->next;
        }
        ListNode*node=curr;
        vector<int>v;
        for(int i=left;i<=right;i++)
        {
            v.push_back(node->val);
            node=node->next;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            curr->val=v[i];
            curr=curr->next;
        }
        return head;
    }
};





// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode*dummy=new ListNode(0);
//         dummy->next=head;
        
//         ListNode*prev=dummy;
        
//         for(int i=0;i<left-1;i++)
//             prev=prev->next;
        
//         ListNode*curr=prev->next;
//         for(int i=0;i<right-left;i++)
//         {
//             ListNode*forw=curr->next;
//             curr->next=forw->next;
//             forw->next=prev->next;
//             prev->next=forw;
//         }
//         return dummy->next;
//     }
// };