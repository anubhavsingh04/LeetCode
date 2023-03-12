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
    ListNode* mergetwo(ListNode*l1,ListNode* l2)
    {
        ListNode*dummy=new ListNode(0);
        ListNode*ptr=dummy;
        
        while(l1||l2)
        {
            if(l1 && l2)
            {
                if(l1->val<l2->val)
                {
                    ptr->next=l1;
                    ptr=l1;
                    l1=l1->next;
                }
                else {
                    ptr->next=l2;
                    ptr=l2;
                    l2=l2->next;
                }
            }
            else {
                if(l1){
                    ptr->next=l1;
                    break;
                }
                else {
                    ptr->next=l2;
                    break;
                }
            }
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*dummy=new ListNode(0);
        ListNode*ptr=dummy;
        ListNode*head=NULL;
        for(int i=0;i<lists.size();i++)
        {
            ListNode*root=mergetwo(lists[i],head);
            head=root;
        }
        return head;
    }
};