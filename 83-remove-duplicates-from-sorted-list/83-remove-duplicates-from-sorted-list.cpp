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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(!head) return NULL;
//         ListNode*curr=head;
//         while(curr->next)
//         {
//             if(curr->val==curr->next->val)
//                 curr->next=curr->next->next;
//             else
//                 curr=curr->next;
//         }
//         return head;
//     }
// };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*curr=head,*agla=head->next;
        while(agla!=NULL)
        {
            if(curr->val!=agla->val)
            {
                curr=curr->next;
                agla=agla->next;
            }
            else {
                while(agla && agla->val==curr->val)
                {
                    agla=agla->next;
                }
                curr->next=agla;
                curr=agla;
                if(agla)
                agla=agla->next;
            }
        }
        return head;
    }
};
