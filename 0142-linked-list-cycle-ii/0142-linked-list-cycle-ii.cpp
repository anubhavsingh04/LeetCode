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
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(fast==NULL || fast->next==NULL) // agr loop nahi hua to
            return NULL;
        slow=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};

// loop removal
// void removeLoop(Node* head)
//     {
//         if(!head) return;
//         Node*slow=head,*fast=head;
//         while(fast && fast->next)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast) break;
//         }
//         if(fast==NULL || fast->next==NULL) return; // means loop nahi hai
//         slow=head;
//         while(slow!=fast)
//         {
//             slow=slow->next;
//             fast=fast->next;
//         }
//         // slow vali val pe loop hai
//         Node*prev=slow->next;
//         while(prev->next!=slow) prev=prev->next;
//         prev->next=NULL;
//     }