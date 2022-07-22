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
    ListNode* partition(ListNode* head, int x) {
        ListNode*frontdummy=new ListNode(0),*backdummy=new ListNode(0);
        ListNode*front=frontdummy,*back=backdummy,*curr=head;
        while(curr)
        {
            if(curr->val>=x)
            {
                back->next=curr;
                back=curr;
            }
            else
            {
                front->next=curr;
                front=curr;
            }
            curr=curr->next;
        }
        back->next=NULL;
        front->next=backdummy->next;
        return frontdummy->next;
    }
};







// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         queue<ListNode*>qsmall,qlarge;
//         ListNode*tmp=head;
//         while(tmp)
//         {
//             if(tmp->val>=x)
//             {
//                 qlarge.push(tmp);
//             }
//             else 
//             {
//                 qsmall.push(tmp);
//             }
//             tmp=tmp->next;
//         }
//         ListNode*dummy= new ListNode(0);
//         tmp=dummy;
//         while(!qsmall.empty())
//         {
//             auto curr=qsmall.front();
//             qsmall.pop();
//             ListNode*newnode=new ListNode(curr->val);
//             tmp->next=newnode;
//             tmp=newnode;
//         }
//         while(!qlarge.empty())
//         {
//             auto curr=qlarge.front();
//             qlarge.pop();
//             ListNode* newnode=new ListNode(curr->val);
//             tmp->next=newnode;
//             tmp=newnode;
//         }
//         tmp->next=NULL;
//         return dummy->next;
//     }
// };