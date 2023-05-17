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
    int pairSum(ListNode* head) {
        int len=0;
        ListNode*curr=head;
        vector<int>v;
        while(curr)
        {
            v.push_back(curr->val);
            curr=curr->next;
            len++;
        }
        int ans=0;
        int i=0,j=v.size()-1;
        while(i<=j)
        {
            ans=max(ans,v[i]+v[j]);
            i++;
            j--;
        }
        return ans;
    }
};