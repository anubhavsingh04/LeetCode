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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode*curr=head,*tmp=head;
        while(curr)
        {
            st.push(curr->val);
            curr=curr->next;
        }
        while(tmp)
        {
            if(tmp->val!=st.top()) return false;
            st.pop();
            tmp=tmp->next;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *slow=head,*fast=head,*prev,*tmp;
//         while(fast&&fast->next)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         prev=slow;
//         slow=slow->next;
//         prev->next=NULL;
//         // reverse half of list
//         while(slow)
//         {
//             tmp=slow->next;
//             slow->next=prev;
//             prev=slow;
//             slow=tmp;
//         }
//         fast=head; slow=prev; // since prev will be pointing at last node 
//         while(slow)
//         {
//             if(slow->val!=fast->val) return false ;
//             slow=slow->next; fast=fast->next;
//         }
//         return true ;
//     }
// };

// More efficient 

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         stack<int>st;
//         queue<int>q;
//         ListNode*curr=head;
//         while(curr!=NULL)
//         {
//              st.push(curr->val); q.push(curr->val); curr=curr->next;
//         }
           
//         while(!st.empty() && !q.empty())
//         {
//             if(st.top()!=q.front()) return false ;
//             st.pop();
//             q.pop();
//         }
//         return true;
//     }
// };
