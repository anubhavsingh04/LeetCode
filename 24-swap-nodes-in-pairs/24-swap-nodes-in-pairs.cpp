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
// Recursion works like magic 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode*tmp=head->next;
        // hypothesis hamari ye hai ki agr ham chote input (3->4) pe apply
        // krenge to ye recursive function hame (4->3) lake de dega 
        // ab bas induction step me hame 1 yani head ki link change krke 4 pe point krana h
        // and tmp ki link ko 1 pe krni hai finally head node temp ho jayega 
        head->next=swapPairs(head->next->next);
        tmp->next=head;
        return tmp;
    }
};


// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(!head||!head->next) return head;
        
//         ListNode*dummy=new ListNode();
//         ListNode*curr=head,*prev=dummy;
//         while(curr&&curr->next)
//         {
//             prev->next=curr->next;
//             curr->next=prev->next->next;
//             prev->next->next=curr;
            
//             prev=curr;
//             curr=curr->next;
//         }
//         return dummy->next;
//     }
// };