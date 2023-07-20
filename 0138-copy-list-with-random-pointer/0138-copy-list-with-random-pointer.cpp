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
        if(head == NULL) head;
        Node* curr = head;
        while(curr!= NULL){
            Node* temp = new Node(curr->val);
            temp -> next = curr -> next;
            curr->next = temp; 
            curr = curr->next-> next;
        }
        curr = head;
        while(curr != NULL){
             if(curr->random )
             curr->next->random = curr->random->next;
             curr = curr->next->next;
        }
        curr = head;
        Node* dummy = new Node(0);
        Node* ptr = dummy;
        Node* front;
        while(curr != NULL){
           front = curr->next->next;
           ptr->next = curr->next;
           curr->next = front;
           ptr = ptr->next;
           curr = front;
        }
        return dummy->next;
    }
};