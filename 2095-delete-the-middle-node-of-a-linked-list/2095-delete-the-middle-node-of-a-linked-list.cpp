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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return NULL;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        while(fast && fast->next)
        {
            prev=prev->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return dummy->next;
    }
};