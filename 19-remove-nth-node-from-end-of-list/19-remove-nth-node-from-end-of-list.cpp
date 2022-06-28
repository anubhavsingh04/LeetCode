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
// make a dummy node and point its next to head 
// make two pointers slow and fast move the fast pointer n times 
// then move slow and fats pointer until fast->next not becomes null return start->next
// if n=5 then also it will give correct ans

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*start=new ListNode();
        start->next=head;
        ListNode*slow=start,*fast=start; // pointing to one previous 
        
        for(int i=0;i<n;i++) // move fast pointer n times a
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};