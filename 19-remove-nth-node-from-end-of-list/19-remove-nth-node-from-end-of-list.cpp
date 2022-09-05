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
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        if(!head) return NULL;
        if(!head->next) return NULL;
        ListNode*curr=head;
        int cnt=0;
        while(curr)
        {
            cnt++;
            curr=curr->next;
        }
        // cout<<cnt<<"$ ";
        if(n==cnt) return head->next;
        n=cnt-n;
        for(int i=0;i<n;i++)
        {
            dummy=dummy->next;
        }
        // cout<<curr->val<<"&";
        dummy->next=dummy->next->next;
        return head;
    }
};