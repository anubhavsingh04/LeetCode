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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;

        for(auto &i:lists)
        {
            ListNode*tmp=i;
            while(tmp)
            {
                v.push_back(tmp->val);
                tmp=tmp->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode*dummy=new ListNode(0);
        ListNode*ptr=dummy;
        int n=v.size();
        for(int i=0;i<v.size();i++)
        {
            ListNode*head=new ListNode(v[i]);
            ptr->next=head;
            ptr=head;
        }
        return dummy->next;
    }
};