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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *prev=NULL,*curr=head,*agla;
        while(curr!=NULL)
        {
            agla=agla->next;
            curr->next=prev;
            prev=curr;
            curr=agla;
        }
        return prev;
    }
};


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *prev=NULL,*next=NULL;
//         while(head)
//         {
//             next=head->next;
//             head->next=prev;
//             prev=head;
//             head=next;
//         }
//         return prev;
//     }
// };