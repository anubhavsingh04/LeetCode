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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode*slow=head;
        while(slow)
        {
            slow=slow->next;
            cnt++;
        }
        int k=cnt-n+1;
        if(k==1) return head->next;
        slow=head;
        for(int i=0;i<k-2;i++)
        {
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};