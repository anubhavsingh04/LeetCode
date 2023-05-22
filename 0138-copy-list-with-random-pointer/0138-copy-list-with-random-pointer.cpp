/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        map<Node*,Node*>mp;
        Node*curr=head;
        while(curr)
        {
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr)
        {
            Node *newnode=mp[curr];
            newnode->next=mp[curr->next];
            newnode->random=mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
    }
};