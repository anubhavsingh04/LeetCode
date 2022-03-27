class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *i=head,*j=head;
        while(j!=NULL&&j->next!=NULL)
        {
            i=i->next;
            j=j->next->next;
        }
        return i;
    }
};