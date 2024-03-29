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
    unordered_map<int,int>mp;
    Solution(ListNode* head) {
        ListNode*curr=head;
        int i=0;
        while(curr)
        {
            mp[i++]=curr->val;
            curr=curr->next;
        }
    }
    
    int getRandom() {
        int n=mp.size();
        return mp[rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */