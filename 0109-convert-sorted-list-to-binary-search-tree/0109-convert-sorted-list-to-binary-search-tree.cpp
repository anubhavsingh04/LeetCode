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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*maketree(vector<int>&v,int start,int end)
    {
        if(start>end) return NULL;
        if(start==end) return new TreeNode(v[start++]);
        int pos=(start+end)/2;
        TreeNode*root=new TreeNode(v[pos]);
        root->left=maketree(v,start,pos-1);
        root->right=maketree(v,pos+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int>v;
        ListNode*tmp=head;
        while(tmp)
        {
            v.push_back(tmp->val);
            tmp=tmp->next;
        }
        return maketree(v,0,v.size()-1);
    }
};